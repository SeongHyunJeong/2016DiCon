#pragma comment(lib, "dsound.lib")
#pragma comment(lib, "dxguid.lib")
#pragma comment(lib, "winmm.lib")


//////////////
// INCLUDES //
//////////////
#include <windows.h>
#include <mmsystem.h>
#include <dsound.h>
#include <stdio.h>
#include"Global.h"
#include<map>

///////////////////////////////////////////////////////////////////////////////
// Class name: Sound
///////////////////////////////////////////////////////////////////////////////
class Sound
{
private:
	struct WaveHeaderType
	{
		char chunkId[4];
		unsigned long chunkSize;
		char format[4];
		char subChunkId[4];
		unsigned long subChunkSize;
		unsigned short audioFormat;
		unsigned short numChannels;
		unsigned long sampleRate;
		unsigned long bytesPerSecond;
		unsigned short blockAlign;
		unsigned short bitsPerSample;
		char dataChunkId[4];
		unsigned long dataSize;
	};

public:
	Sound();
	Sound(const Sound&);
	~Sound();
	bool Initialize(HWND);
	void Shutdown();//다이렉트 사운드 API를 아예 해제한다.
	void Add(char * path, char * alias);// 재생할 사운드는 이 함수로 씬의 생성자에서 모두 로드해 놓는다. path는 경로이고 alias는 재생, 중지 등의 명령을 내릴 때 사용할 별명이다.
	void Play(char * alias, bool loop);//이 함수는 지정한 alias에 해당하는 wavefile을 무한반복 또는 한 번만 재생할 수 있다.
	void Stop(char * alias);//지정한 alias에 대한 이차 버퍼를 shutdown 한다.

private:
	bool InitializeDirectSound(HWND);
	void ShutdownDirectSound();

	bool LoadWaveFile(char*, IDirectSoundBuffer8**);
	void ShutdownWaveFile(IDirectSoundBuffer8**);

	bool PlayWaveFile(char * alias, bool loop);

private:
	IDirectSound8* m_DirectSound;
	IDirectSoundBuffer* m_primaryBuffer;
	map<char *, IDirectSoundBuffer8 *> m_secondaryBufferMap;

};

extern Sound sound;