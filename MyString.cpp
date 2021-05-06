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

// 복사 생성자
CMyString::CMyString(const CMyString& rhs)
	: m_pszData(nullptr)
	,m_nLength(0)
{
	this->SetString(rhs.GetString());
	
	//m_pszData = new char;
	//*m_pszData = *rhs.m_pszData;
}

// 연산자 재정의
CMyString& CMyString::operator=(const CMyString& rhs)
{
	// 자기 자신에 대한 대입이면 아무것도 하지 않음
	if (this != &rhs)
		this->SetString(rhs.GetString());
	//*m_pszData = *rhs.m_pszData;
	return *this;
}

// 변환 생성자(const char* 에 대한 변환)
CMyString::CMyString(const char* pszParam)
	:m_pszData(nullptr)
	, m_nLength(0)
{
	SetString(pszParam);
}

int CMyString::SetString(const char* pszParam)
{
	Release();

	// nullptr 인수로 함수 호출(pszParam == nullptr)했다는 것은 메모리 해제하고 nullptr로 초기화하는 것
	if (pszParam == nullptr)
		return 0;

	// 길이가 0인 문자열도 초기화로 인식하고 처리한다
	int nLength = strlen(pszParam);
	
	if (nLength == 0)
		return 0;

	// 문자열 끝 nullptr까지 고려해서 메모리를 할당함
	m_pszData = new char[nLength + 1];

	// 새로 할당한ㅇ 메모리에 문자열을 저장함
	strcpy_s(m_pszData, sizeof(char) * (nLength + 1), pszParam); // 복사 문자열, 문자열 길이, 원본 문자열
	m_nLength = nLength;

	//문자열의 길이를 반환
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
	//이 함수가 여러번 호출될 경우를 고려해 주요 멤버를 초기화함
	if (m_pszData != nullptr)
		delete[] m_pszData;

	m_pszData = nullptr;
	m_nLength = 0;
}
