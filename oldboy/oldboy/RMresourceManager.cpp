#include "stdafx.h"
#include "RMmacro.h"
#include "RMdefine.h"
#include "RMresourceManager.h"
#include "RMimage.h"
#include "RMxmlLoader.h"
#include "RMmusicData.h"

CRMresourceManager::CRMresourceManager(void):
	m_pWICFactory(nullptr)
{
}


CRMresourceManager::~CRMresourceManager(void)
{
	SafeRelease(m_pWICFactory);

	InitializeArray();
}


void CRMresourceManager::InitializeArray()
{
	for ( auto& toBeDelete : m_TextureArray )
	{
		SafeDelete( toBeDelete );
	}
}

void CRMresourceManager::InitializeAlbum()
{
	if ( m_TextureArray[OBJECT_ALBUM_IMAGE] != nullptr )
	{
		SafeDelete( m_TextureArray[OBJECT_ALBUM_IMAGE] );
	}
}

//////////////////////////////////////////////////////////////////////////
//CLSID_WICImagingFactory는 1, 2가 나뉘어져 있음
//각 PC에 따라서 구동되는 것이 다르기 때문에 해당 내용에 대해서 확인하는 방어 코드 작성
//////////////////////////////////////////////////////////////////////////

HRESULT CRMresourceManager::CreateFactory()
{
	HRESULT hr = S_FALSE;

	if ( m_pWICFactory == nullptr )
	{
		hr = CoCreateInstance( CLSID_WICImagingFactory, NULL, CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&m_pWICFactory) );

		if ( hr == REGDB_E_CLASSNOTREG )
		{
			hr = CoCreateInstance( CLSID_WICImagingFactory1, NULL, CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&m_pWICFactory) );

			if ( hr == REGDB_E_CLASSNOTREG )
			{
				hr = CoCreateInstance( CLSID_WICImagingFactory2, NULL, CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&m_pWICFactory) );
			}
		}

	}

	return hr;
}


// 기본 Resource폴더의 텍스쳐 로드
HRESULT CRMresourceManager::CreateTexture()
{
	InitializeArray();

	HRESULT hr = S_FALSE;
	CRMimage* texture = new CRMimage();
	hr = texture->CreateImage( BG_IMAGE_TITLE );
	
	if ( hr == S_OK )
	{
		m_TextureArray[OBJECT_BG_IMAGE_TITLE] = texture;
	}
	else
	{
		printConsole( ERROR_LOAD_IMAGE_CONSOLE, hr);
		m_TextureArray[OBJECT_BG_IMAGE_TITLE] = nullptr;
		SafeDelete(texture);
	}


	texture = new CRMimage();
	hr = texture->CreateImage( BG_IMAGE_SELECT );
	
	if ( hr == S_OK )
	{
		m_TextureArray[OBJECT_BG_IMAGE_SELECT] = texture;
	}
	else
	{
		printConsole( ERROR_LOAD_IMAGE_CONSOLE, hr);
		m_TextureArray[OBJECT_BG_IMAGE_SELECT] = nullptr;
		SafeDelete(texture);
	}

	texture = new CRMimage();
	hr = texture->CreateImage( BG_IMAGE_RESULT );
	
	if ( hr == S_OK )
	{
		m_TextureArray[OBJECT_BG_IMAGE_RESULT] = texture;
	}
	else
	{
		printConsole( ERROR_LOAD_IMAGE_CONSOLE, hr);
		m_TextureArray[OBJECT_BG_IMAGE_RESULT] = nullptr;
		SafeDelete(texture);
	}

	//////////////////////////////////////////////////////////////////////////
	// 추가중 
	texture = new CRMimage();
	hr = texture->CreateImage( L"./Resource/image_pa_play_01.png" );

	if ( hr == S_OK )
	{
		m_TextureArray[OBJECT_PAUSE_IMAGE_PLAY_CANCEL] = texture;
	}
	else
	{
		printConsole( ERROR_LOAD_IMAGE_CONSOLE, hr);
		m_TextureArray[OBJECT_PAUSE_IMAGE_PLAY_CANCEL] = nullptr;
		SafeDelete(texture);
	}

	texture = new CRMimage();
	hr = texture->CreateImage( L"./Resource/image_pa_play_02.png" );

	if ( hr == S_OK )
	{
		m_TextureArray[OBJECT_PAUSE_IMAGE_PLAY_OK] = texture;
	}
	else
	{
		printConsole( ERROR_LOAD_IMAGE_CONSOLE, hr);
		m_TextureArray[OBJECT_PAUSE_IMAGE_PLAY_OK] = nullptr;
		SafeDelete(texture);
	}



	texture = new CRMimage();
	hr = texture->CreateImage( L"./Resource/image_pa_play_01.png" );

	if ( hr == S_OK )
	{
		m_TextureArray[OBJECT_PAUSE_IMAGE_SELECT_CANCEL] = texture;
	}
	else
	{
		printConsole( ERROR_LOAD_IMAGE_CONSOLE, hr);
		m_TextureArray[OBJECT_PAUSE_IMAGE_SELECT_CANCEL] = nullptr;
		SafeDelete(texture);
	}

	texture = new CRMimage();
	hr = texture->CreateImage( L"./Resource/image_pa_play_02.png" );

	if ( hr == S_OK )
	{
		m_TextureArray[OBJECT_PAUSE_IMAGE_SELECT_OK] = texture;
	}
	else
	{
		printConsole( ERROR_LOAD_IMAGE_CONSOLE, hr);
		m_TextureArray[OBJECT_PAUSE_IMAGE_SELECT_OK] = nullptr;
		SafeDelete(texture);
	}





	texture = new CRMimage();
	hr = texture->CreateImage( L"./Resource/image_pa_play_01.png" );

	if ( hr == S_OK )
	{
		m_TextureArray[OBJECT_PAUSE_IMAGE_TITLE_CANCEL] = texture;
	}
	else
	{
		printConsole( ERROR_LOAD_IMAGE_CONSOLE, hr);
		m_TextureArray[OBJECT_PAUSE_IMAGE_TITLE_CANCEL] = nullptr;
		SafeDelete(texture);
	}

	texture = new CRMimage();
	hr = texture->CreateImage( L"./Resource/image_pa_play_02.png" );

	if ( hr == S_OK )
	{
		m_TextureArray[OBJECT_PAUSE_IMAGE_TITLE_OK] = texture;
	}
	else
	{
		printConsole( ERROR_LOAD_IMAGE_CONSOLE, hr);
		m_TextureArray[OBJECT_PAUSE_IMAGE_TITLE_OK] = nullptr;
		SafeDelete(texture);
	}
	//////////////////////////////////////////////////////////////////////////
	//이하 플레이 화면
	texture = new CRMimage();
	hr = texture->CreateImage( PLAY_IMAGE_JUDGE_RING );

	if ( hr == S_OK )
	{
		m_TextureArray[OBJECT_JUDGERING] = texture;
	}
	else
	{
		printConsole( ERROR_LOAD_IMAGE_CONSOLE, hr);
		m_TextureArray[OBJECT_BG_IMAGE_PLAY] = nullptr;
		InitializeArray();

		return hr;
	}

	texture = new CRMimage();
	hr = texture->CreateImage( PLAY_IMAGE_BLUE_GAUGE );

	if ( hr == S_OK )
	{
		m_TextureArray[OBJECT_GAUGE_2P] = texture;
	}
	else
	{
		printConsole( ERROR_LOAD_IMAGE_CONSOLE, hr);
		m_TextureArray[OBJECT_BG_IMAGE_PLAY] = nullptr;
		InitializeArray();

		return hr;
	}

	texture = new CRMimage();
	hr = texture->CreateImage( PLAY_IMAGE_RED_GAUGE );

	if ( hr == S_OK )
	{
		m_TextureArray[OBJECT_GAUGE_1P] = texture;
	}
	else
	{
		printConsole( ERROR_LOAD_IMAGE_CONSOLE, hr);
		m_TextureArray[OBJECT_BG_IMAGE_PLAY] = nullptr;
		InitializeArray();

		return hr;
	}
	
	return hr;
}

HRESULT CRMresourceManager::CreateTexture( const std::string& folderName )
{
	
	HRESULT hr = S_FALSE;
	CRMimage* texture;

	// 기본 자원 로드
	hr = CreateTexture();
	if ( hr == S_FALSE )
	{
		printConsole( ERROR_LOAD_IMAGE_CONSOLE, hr);
		InitializeArray();
		return hr;
	}
	

	// 곡마다 바뀌는 정보 로드

	texture = new CRMimage();
	hr = texture->CreateImage( GetFilePath( folderName, CRMxmlLoader::GetInstance()->GetMusicData( folderName )->GetImageBackground() ) );
	
	if ( hr == S_OK )
	{
		m_TextureArray[OBJECT_BG_IMAGE_PLAY] = texture;
	}
	else
	{
		printConsole( ERROR_LOAD_IMAGE_CONSOLE, hr);
		m_TextureArray[OBJECT_BG_IMAGE_PLAY] = nullptr;
		InitializeArray();

		return hr;
	}

	texture = new CRMimage();
	hr = texture->CreateImage( GetFilePath( folderName, CRMxmlLoader::GetInstance()->GetMusicData( folderName )->GetImageShutter() ) );
	
	if ( hr == S_OK )
	{
		m_TextureArray[OBJECT_SHUTTER] = texture;
	}
	else
	{
		printConsole( ERROR_LOAD_IMAGE_CONSOLE, hr);
		m_TextureArray[OBJECT_SHUTTER] = nullptr;
		InitializeArray();

		return hr;
	}

	texture = new CRMimage();
	hr = texture->CreateImage( GetFilePath( folderName, CRMxmlLoader::GetInstance()->GetMusicData( folderName )->GetImageNote1() ) );
	
	if ( hr == S_OK )
	{
		m_TextureArray[OBJECT_NOTE_NORMAL_1] = texture;
	}
	else
	{
		printConsole( ERROR_LOAD_IMAGE_CONSOLE, hr);
		m_TextureArray[OBJECT_NOTE_NORMAL_1] = nullptr;
		InitializeArray();

		return hr;
	}

	texture = new CRMimage();
	hr = texture->CreateImage( GetFilePath( folderName, CRMxmlLoader::GetInstance()->GetMusicData( folderName )->GetImageNote2() ) );
	
	if ( hr == S_OK )
	{
		m_TextureArray[OBJECT_NOTE_NORMAL_2] = texture;
	}
	else
	{
		printConsole( ERROR_LOAD_IMAGE_CONSOLE, hr);
		m_TextureArray[OBJECT_NOTE_NORMAL_2] = nullptr;
		InitializeArray();

		return hr;
	}

	texture = new CRMimage();
	hr = texture->CreateImage( GetFilePath( folderName, CRMxmlLoader::GetInstance()->GetMusicData( folderName )->GetImageNoteEffect() ) );
	
	if ( hr == S_OK )
	{
		m_TextureArray[OBJECT_NOTE_HIT] = texture;
	}
	else
	{
		printConsole( ERROR_LOAD_IMAGE_CONSOLE, hr);
		m_TextureArray[OBJECT_NOTE_HIT] = nullptr;
		InitializeArray();

		return hr;
	}

	return hr;
}


HRESULT CRMresourceManager::CreateTextureAlbum( const std::string& folderName )
{
	InitializeAlbum();

	HRESULT hr = S_FALSE;
	CRMimage* texture;

	texture = new CRMimage();
	hr = texture->CreateImage( GetFilePath( folderName, CRMxmlLoader::GetInstance()->GetMusicData( folderName )->GetImageAlbum() ) );
	
	if ( hr == S_OK )
	{
		m_TextureArray[OBJECT_ALBUM_IMAGE] = texture;
	}
	else
	{
		printConsole( ERROR_LOAD_IMAGE_CONSOLE, hr);
		InitializeAlbum();
		return hr;
	}

	return hr;
}

std::wstring CRMresourceManager::GetFilePath( const std::string& folderName, const std::string& resourceName ) const
{
	std::string str = MUSIC_FOLDER;
	str.append( folderName );
	str.append( FOLDER_SLASH );
	str.append( resourceName );

	std::wstring wstr(str.length(),L' ');
	copy(str.begin(),str.end(),wstr.begin());

	return wstr;
}

