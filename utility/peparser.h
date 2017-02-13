#ifndef PEPARSER_H
#define PEPARSER_H

class peFile
{
	public:
	
	peFile::peFile(): 	m_hFile{NULL},	m_hFileMap{NULL}, m_pvFileAdr{NULL}, m_pImageSectionHeader{NULL}, m_pImageExportDirectory{NULL}, m_pszFileName{NULL}
	{
	}
	peFile::~peFile()
	{
		if (m_hFile != NULL)
			ClosePE();
		if (m_pImageSectionHeader != NULL)
		{
			delete [] m_pImageSectionHeader;
			m_pImageSectionHeader = NULL;
		}
		if (m_pImageExportDirectory != NULL) 
		{
			delete [] m_pImageExportDirectory;
			m_pImageExportDirectory = NULL;
		}
	}

	private:

}


#endif // PEPARSER_H