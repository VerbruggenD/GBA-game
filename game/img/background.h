
//{{BLOCK(background)

//======================================================================
//
//	background, 256x256@8, 
//	Transparent palette entry: 0.
//	+ palette 256 entries, not compressed
//	+ 424 tiles (t|f reduced) not compressed
//	+ regular map (in SBBs), not compressed, 32x32 
//	Total size: 512 + 27136 + 2048 = 29696
//
//	Time-stamp: 2022-01-06, 13:10:57
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.16
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_BACKGROUND_H
#define GRIT_BACKGROUND_H

#define backgroundTilesLen 27136
extern const unsigned int backgroundTiles[6784];

#define backgroundMapLen 2048
extern const unsigned short backgroundMap[1024];

#define backgroundPalLen 512
extern const unsigned short backgroundPal[256];

#endif // GRIT_BACKGROUND_H

//}}BLOCK(background)
