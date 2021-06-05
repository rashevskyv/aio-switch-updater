#pragma once 

#include <borealis.hpp>
#include <switch.h>
#include <json.hpp>

class DownloadCheatsPage : public brls::AppletFrame
{
    protected:
        brls::List* list;
        brls::Label* label;
        brls::ListItem* del;
        uint64_t tid = 0;
        std::string bid = "";
        u32 version = 0;

        DownloadCheatsPage(uint64_t tid);
        void GetBuildID();
        void GetBuildIDFromDmnt();
        void GetVersion();
        void GetBuildIDFromFile();
        void WriteCheats(std::string cheatContent);
        void DeleteCheats();

        typedef struct {
            u64 base;
            u64 size;
        } DmntMemoryRegionExtents;

        typedef struct {
            u64 process_id;
            u64 title_id;
            DmntMemoryRegionExtents main_nso_extents;
            DmntMemoryRegionExtents heap_extents;
            DmntMemoryRegionExtents alias_extents;
            DmntMemoryRegionExtents address_space_extents;
            u8 main_nso_build_id[0x20];
        } DmntCheatProcessMetadata;
};

class DownloadCheatsPage_CheatSlips : public DownloadCheatsPage {

    private:
        brls::ToggleListItem* listItem;
        std::vector<std::pair<brls::ToggleListItem*, int>> toggles;
        std::string GetCheatsTitle(nlohmann::json cheat);
        void ShowCheatsContent(nlohmann::ordered_json titles);

    public:
        DownloadCheatsPage_CheatSlips(uint64_t tid);
};

class DownloadCheatsPage_GbaTemp : public DownloadCheatsPage {
    private:
        brls::ListItem* listItem;

    public:
        DownloadCheatsPage_GbaTemp(uint64_t tid);
};