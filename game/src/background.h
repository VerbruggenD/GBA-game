
//{{BLOCK(background)

//======================================================================
//
//	background, 256x256@8, 
//	+ palette 256 entries, not compressed
//	+ 292 tiles (t|f|p reduced) not compressed
//	+ regular map (flat), not compressed, 32x32 
//	Total size: 512 + 18688 + 2048 = 21248
//
//	Time-stamp: 2022-01-09, 17:45:58
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.6
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_BACKGROUND_H
#define GRIT_BACKGROUND_H

#define backgroundTilesLen 18688
extern const unsigned short backgroundTiles[9344];

#define backgroundMapLen 2048
extern const unsigned short backgroundMap[1024];

#define menuMapLen 2048
extern const unsigned short menuMap[1024];

#define boundaryMap 2048
extern const unsigned short boundaryMap[1024]

#define backgroundPalLen 512
extern const unsigned short backgroundPal[256];

#endif // GRIT_BACKGROUND_H

//}}BLOCK(background)
