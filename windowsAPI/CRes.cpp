#include "framework.h"
#include "CRes.h"

CRes::CRes()
{
}

CRes::~CRes()
{
}

void CRes::SetKey(wstring &strKey)
{
	m_strKey = strKey;
}

void CRes::SetRelativePath(wstring &strPath)
{
	m_strRelativePath = strPath;
}

const wstring& CRes::GetKey()
{
	return m_strKey;
}

const wstring& CRes::GetRekativePath()
{
	return m_strRelativePath;
}
