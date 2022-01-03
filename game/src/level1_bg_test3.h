
//{{BLOCK(level1_bg)

//======================================================================
//
//	level1_bg, 256x256@8, 
//	+ palette 256 entries, not compressed
//	+ 445 tiles (t|f|p reduced) not compressed
//	+ regular map (in SBBs), not compressed, 32x32 
//	Total size: 512 + 28480 + 2048 = 31040
//
//	Time-stamp: 2021-12-29, 14:18:18
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.16
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_LEVEL1_BG_H
#define GRIT_LEVEL1_BG_H

#define level1_bgTilesLen 28480
extern const unsigned int level1_bgTiles[7120];

#define level1_bgMapLen 2048
extern const unsigned short level1_bgMap[1024];

#define level1_bgPalLen 512
extern const unsigned short level1_bgPal[256];

#endif // GRIT_LEVEL1_BG_H

//}}BLOCK(level1_bg)
