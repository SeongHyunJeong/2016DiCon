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
	void Shutdown();//���̷�Ʈ ���� API�� �ƿ� �����Ѵ�.
	void Add(char * path, char * alias);// ����� ����� �� �Լ��� ���� �����ڿ��� ��� �ε��� ���´�. path�� ����̰� alias�� ���, ���� ���� ����� ���� �� ����� �����̴�.
	void Play(char * alias, bool loop);//�� �Լ��� ������ alias�� �ش��ϴ� wavefile�� ���ѹݺ� �Ǵ� �� ���� ����� �� �ִ�.
	void Stop(char * alias);//������ alias�� ���� ���� ���۸� shutdown �Ѵ�.

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