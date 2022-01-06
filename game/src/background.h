
//{{BLOCK(background)

//======================================================================
//
//	background, 240x160@8, 
//	+ palette 256 entries, not compressed
//	+ 421 tiles (t|f|p reduced) not compressed
//	+ regular map (flat), not compressed, 30x20 
//	Total size: 512 + 26944 + 1200 = 28656
//
//	Time-stamp: 2022-01-06, 14:37:34
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.6
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_BACKGROUND_H
#define GRIT_BACKGROUND_H

#define backgroundTilesLen 26944
extern const unsigned short backgroundTiles[13472];

#define backgroundMapLen 1200
extern const unsigned short backgroundMap[600];

#define backgroundPalLen 512
extern const unsigned short backgroundPal[256];

#endif // GRIT_BACKGROUND_H

//}}BLOCK(background)
