#include "Basic.hlsli"

Texture2D<float4> tex : register(t0);  // 0�ԃX���b�g�ɐݒ肳�ꂽ�e�N�X�`��
SamplerState smp : register(s0);      // 0�ԃX���b�g�ɐݒ肳�ꂽ�T���v���[

float4 main(VSOutput input) : SV_TARGET
{
	 input.uv = float2(input.uv.x + offset.x,input.uv.y + offset.y);
	//// �e�N�X�`���}�b�s���O
	float4 texcolor = tex.Sample(smp,input.uv) *color;

	//// ����x
	//const float shininess = 4.0f;
	//// ���_���王�_�ւ̕����x�N�g��
	//float3 eyedir = normalize(cameraPos - input.worldpos.xyz);

	//// �����ˌ�
	//float3 ambient = m_ambient;

	//// �V�F�[�f�B���O�ɂ��F
	//float4 shadecolor = float4(ambientColor * ambient, m_alpha);

	//for (int i = 0; i < DIRLIGHT_NUM; i++) {
	//	if (dirLights[i].active) {
	//		// ���C�g�Ɍ������x�N�g���Ɩ@���̓���
	//		float3 dotlightnormal = dot(dirLights[i].lightv, input.normal);
	//		// ���ˌ��x�N�g��
	//		float3 reflect = normalize(-dirLights[i].lightv + 2 * dotlightnormal * input.normal);
	//		// �g�U���ˌ�
	//		float3 diffuse = dotlightnormal * m_diffuse;
	//		// ���ʔ��ˌ�
	//		float3 specular = pow(saturate(dot(reflect, eyedir)), shininess) * m_specular;

	//		// �S�ĉ��Z����
	//		shadecolor.rgb += (diffuse + specular) * dirLights[i].lightcolor;
	//	}
	//}

	//// �V�F�[�f�B���O�ɂ��F�ŕ`��
	//return shadecolor * texcolor;
	
	const float _ThresholdMin=0.2;
	const float _ThresholdMax=0.8;
	float3 lightv = normalize(float3(0, 1, 0)); // �E�����@�����̃��C�g

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