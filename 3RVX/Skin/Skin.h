#pragma once

#pragma comment(lib, "gdiplus.lib")

#include <Windows.h>
#include <gdiplus.h>

#include <list>
#include <vector>

#include "../TinyXml2/tinyxml2.h"
#include "OSDSkin.h" // forward declare this later??
#include "SkinInfo.h"

class Meter;
class SliderKnob;
class SoundPlayer;

#define SKIN_DEFAULT_UNITS 10

class Skin : SkinInfo {
public:
    Skin(std::wstring skinXML);
    ~Skin();

    bool HasOSD(char *osdName);
    int DefaultVolumeUnits();

public:
    OSDSkin *VolumeOSD();

    Gdiplus::Bitmap *muteBackground;
    Gdiplus::Bitmap *muteMask;

    Gdiplus::Bitmap *ejectBackground;
    Gdiplus::Bitmap *ejectMask;

    Gdiplus::Bitmap *volumeSliderBackground;
    Gdiplus::Bitmap *volumeSliderMask;
    std::vector<Meter *> volumeSliderMeters;
    SliderKnob *volumeSliderKnob;

private:
    OSDSkin *_volumeOSD;

    Gdiplus::Bitmap *OSDBgImg(char *osdName);
    Gdiplus::Bitmap *OSDMask(char *osdName);
    SoundPlayer *OSDSound(char *osdName);

    std::vector<HICON> Iconset(char *osdName);

    Gdiplus::Bitmap *SliderBgImg(char *sliderName);
    Gdiplus::Bitmap *SliderMask(char *sliderName);
    SliderKnob *Knob(char *sliderName);

    std::vector<Meter *> Meters(tinyxml2::XMLElement *parentElement);
    Meter *LoadMeter(tinyxml2::XMLElement *meterXMLElement);

    Gdiplus::Bitmap *Image(tinyxml2::XMLElement *element, char *attrName);
    std::wstring ImageName(tinyxml2::XMLElement *meterXMLElement);
    Gdiplus::Font *Font(tinyxml2::XMLElement *meterXMLElement);
    Gdiplus::StringAlignment Alignment(tinyxml2::XMLElement *meterXMLElement);

    tinyxml2::XMLElement *SubElement(char *parent, char *child);

    int DefaultOSDUnits(char *osdName);
};
