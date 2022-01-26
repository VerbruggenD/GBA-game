
//{{BLOCK(Startscreen)

//======================================================================
//
//	Startscreen, 256x256@8, 
//	+ palette 256 entries, not compressed
//	+ 1 tiles (t|f|p reduced) not compressed
//	+ regular map (flat), not compressed, 32x32 
//	Total size: 512 + 64 + 2048 = 2624
//
//	Time-stamp: 2022-01-24, 20:04:51
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.6
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_STARTSCREEN_H
#define GRIT_STARTSCREEN_H

#define StartscreenTilesLen 64
extern const unsigned short StartscreenTiles[32];

#define StartscreenMapLen 2048
extern const unsigned short StartscreenMap[1024];

#define StartscreenPalLen 512
extern const unsigned short StartscreenPal[256];

#endif // GRIT_STARTSCREEN_H

//}}BLOCK(Startscreen)
