#pragma once

class CMyString
{
public:
	CMyString();
	~CMyString();

	// ���� ������
	CMyString(const CMyString& rhs);

	// ��ȯ ������(const char* �� ���� ��ȯ)                     
	explicit CMyString(const char* pszParam);

private:
	// ���ڿ��� �����ϱ� ���� ���� �Ҵ��� �޸𸮸� ����Ű�� ������
	char* m_pszData = nullptr;
	// ����� ���ڿ��� ����
	int m_nLength;

public:
	int SetString(const char* pszParam);

	// ��� �б⸸ �����ϹǷ� �޼��带 ���ȭ
	const char* GetString() const;
	void Release();

	// ������ ������
	CMyString& operator=(const CMyString& rhs);

	// char* ���� ��ȯ
	operator char* (void) const
	{
		return m_pszData;
	}

};

