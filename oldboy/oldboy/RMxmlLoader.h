#pragma once



class CRMmusicData;
class CRMnoteData;

class CRMxmlLoader
{
	SINGLETON(CRMxmlLoader);


public:
	CRMxmlLoader(void);
	~CRMxmlLoader(void);
	
	void				LoadMusicData( const std::string& folderName );
	void				LoadNoteData( const std::string& folderName );
	CRMnoteData*		GetNoteFirst();
	HRESULT				DeleteNoteFirst();

	CRMmusicData*		GetMusicData( std::string folderName ) { return m_MusicDataMap[folderName]; }
private:
	//           폴더이름  음악개체
	std::map<std::string, CRMmusicData*>	m_MusicDataMap;
	std::list<CRMnoteData*>					m_NoteList;
};
