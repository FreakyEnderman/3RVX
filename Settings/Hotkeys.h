#pragma once

#include "Tab.h"

#include "../3RVX/HotkeyInfo.h"

class Hotkeys : public Tab {
public:
    virtual void SaveSettings();

protected:
    virtual void Initialize();
    virtual void LoadSettings();

private:
    std::vector<HotkeyInfo> _keyInfo;

    void LoadSelection();
    void LoadSelection(int index);

private:
    bool OnAddButtonClick();
    bool OnRemoveButtonClick();
    bool OnKeysButtonClick();
    void OnKeyListItemChange(NMLISTVIEW *lv);
    void OnKeyListSelectionChange(int index);

private:
    /* Controls: */
    ListView _keyList;
    Button _add;
    Button _remove;

    Button _keys;
    ComboBox _action;

private:
    /* Strings: */
    std::wstring hotkeysColumnStr = L"Hotkeys";
    std::wstring actionColumnStr = L"Action";
};