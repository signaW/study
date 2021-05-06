#include "pch.h"
#include "MyString.h"

void TestFunc(const CMyString& strParam)
{
    cout << strParam << endl;
}

int _tmain(int argc, _TCHAR* argv[])
{

    CMyString strData, strTest;
    strData.SetString("Hello");
    strTest.SetString("World");

    TestFunc(strData);

    // 복사 생성
    CMyString strNewData(strData);
    cout << strNewData.GetString() << endl;

    // 단순 대입 연산자 호출
    strNewData = strTest;
    cout << strNewData.GetString() << endl;




    //CMyString strData;
    //strData.SetString("Hello");
    //cout << strData.GetString() << endl;

    return 0;
}