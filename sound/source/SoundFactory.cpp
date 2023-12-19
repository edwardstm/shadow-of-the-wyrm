#include <cassert>
#include "SoundFactory.hpp"
#include "NullSound.hpp"
#include "SDLSound.hpp"

using namespace std;

const string SoundID::SOUND_SDL = "sdl";

SoundID::SoundID()
{
}

SoundID::~SoundID()
{
}

SoundPtr SoundFactory::create_sound(const string& sound_id)
{
	SoundPtr sound;

	if (sound_id == SoundID::SOUND_SDL)
	{
		sound = std::make_shared<SDLSound>();
	}
	else
	{
		sound = std::make_shared<NullSound>();
	}

	return sound;
}

SoundPtr SoundFactory::create_sound(ClassIdentifier sound_ci)
{
	SoundPtr sound;

	if (sound_ci == ClassIdentifier::CLASS_ID_SDL_SOUND)
	{
		sound = std::make_shared<SDLSound>();
	}
	else if (sound_ci == ClassIdentifier::CLASS_ID_NULL_SOUND)
	{
		sound = std::make_shared<NullSound>();
	}
	else
	{
		assert(false && "Unexpected class_id for SoundFactory::create_sound");
	}

	return sound;
}