#include "pch.h"
#include "MyString.h"

CMyString::CMyString()
	: m_pszData(nullptr)
	, m_nLength(0)
{
}

CMyString::~CMyString()
{
	Release();
}

// ���� ������
CMyString::CMyString(const CMyString& rhs)
	: m_pszData(nullptr)
	,m_nLength(0)
{
	this->SetString(rhs.GetString());
	
	//m_pszData = new char;
	//*m_pszData = *rhs.m_pszData;
}

// ������ ������
CMyString& CMyString::operator=(const CMyString& rhs)
{
	// �ڱ� �ڽſ� ���� �����̸� �ƹ��͵� ���� ����
	if (this != &rhs)
		this->SetString(rhs.GetString());
	//*m_pszData = *rhs.m_pszData;
	return *this;
}

// ��ȯ ������(const char* �� ���� ��ȯ)
CMyString::CMyString(const char* pszParam)
	:m_pszData(nullptr)
	, m_nLength(0)
{
	SetString(pszParam);
}

int CMyString::SetString(const char* pszParam)
{
	Release();

	// nullptr �μ��� �Լ� ȣ��(pszParam == nullptr)�ߴٴ� ���� �޸� �����ϰ� nullptr�� �ʱ�ȭ�ϴ� ��
	if (pszParam == nullptr)
		return 0;

	// ���̰� 0�� ���ڿ��� �ʱ�ȭ�� �ν��ϰ� ó���Ѵ�
	int nLength = strlen(pszParam);
	
	if (nLength == 0)
		return 0;

	// ���ڿ� �� nullptr���� ����ؼ� �޸𸮸� �Ҵ���
	m_pszData = new char[nLength + 1];

	// ���� �Ҵ��Ѥ� �޸𸮿� ���ڿ��� ������
	strcpy_s(m_pszData, sizeof(char) * (nLength + 1), pszParam); // ���� ���ڿ�, ���ڿ� ����, ���� ���ڿ�
	m_nLength = nLength;

	//���ڿ��� ���̸� ��ȯ
	return nLength;

	//char* Temporary = new char;
	//m_pszData = *pszParam;
	//return 0;
}


const char* CMyString::GetString() const
{
	return m_pszData;
}


void CMyString::Release()
{
	//�� �Լ��� ������ ȣ��� ��츦 ����� �ֿ� ����� �ʱ�ȭ��
	if (m_pszData != nullptr)
		delete[] m_pszData;

	m_pszData = nullptr;
	m_nLength = 0;
}
