#include "Basic.hlsli"

Texture2D<float4> tex : register(t0);  // 0番スロットに設定されたテクスチャ
SamplerState smp : register(s0);      // 0番スロットに設定されたサンプラー

float4 main(VSOutput input) : SV_TARGET
{
	 input.uv = float2(input.uv.x + offset.x,input.uv.y + offset.y);
	//// テクスチャマッピング
	float4 texcolor = tex.Sample(smp,input.uv) *color;

	//// 光沢度
	//const float shininess = 4.0f;
	//// 頂点から視点への方向ベクトル
	//float3 eyedir = normalize(cameraPos - input.worldpos.xyz);

	//// 環境反射光
	//float3 ambient = m_ambient;

	//// シェーディングによる色
	//float4 shadecolor = float4(ambientColor * ambient, m_alpha);

	//for (int i = 0; i < DIRLIGHT_NUM; i++) {
	//	if (dirLights[i].active) {
	//		// ライトに向かうベクトルと法線の内積
	//		float3 dotlightnormal = dot(dirLights[i].lightv, input.normal);
	//		// 反射光ベクトル
	//		float3 reflect = normalize(-dirLights[i].lightv + 2 * dotlightnormal * input.normal);
	//		// 拡散反射光
	//		float3 diffuse = dotlightnormal * m_diffuse;
	//		// 鏡面反射光
	//		float3 specular = pow(saturate(dot(reflect, eyedir)), shininess) * m_specular;

	//		// 全て加算する
	//		shadecolor.rgb += (diffuse + specular) * dirLights[i].lightcolor;
	//	}
	//}

	//// シェーディングによる色で描画
	//return shadecolor * texcolor;
	
	const float _ThresholdMin=0.2;
	const float _ThresholdMax=0.8;
	float3 lightv = normalize(float3(0, 1, 0)); // 右下奥　向きのライト

	float3 eyeDir = normalize(cameraPos - input.worldpos.xyz);
	float3 halfVec = normalize(lightv + eyeDir);
	float intensity = saturate(dot(normalize(input.normal), halfVec));
	float Diffuse = pow(intensity, 10); 
	float Dif = smoothstep(_ThresholdMin, _ThresholdMax, Diffuse);

	float light = smoothstep(_ThresholdMin, _ThresholdMax, intensity);
	float dark = 1 - smoothstep(_ThresholdMin, _ThresholdMax, intensity);

	float4 lightColor = texcolor;
	float4 darkColor = float4(texcolor.xyz * 0.3,1.0);


	float4 ambient = dark * darkColor;
	float4 diffuse = light * lightColor + dark * darkColor;
	float4 specular = Dif * float4(1.0f, 1.0f, 1.0f, 1.0f);
	float4 ads = ambient + diffuse + specular;

	return ads;
}