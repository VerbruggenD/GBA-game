
//{{BLOCK(testbackground)

//======================================================================
//
//	testbackground, 256x256@8, 
//	+ palette 256 entries, not compressed
//	+ 584 tiles (t|f|p reduced) not compressed
//	+ regular map (in SBBs), not compressed, 32x32 
//	Total size: 512 + 37376 + 2048 = 39936
//
//	Time-stamp: 2021-12-15, 17:57:17
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.16
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_TESTBACKGROUND_H
#define GRIT_TESTBACKGROUND_H

#define testbackgroundTilesLen 37376
extern const unsigned int testbackgroundTiles[9344];

#define testbackgroundMapLen 2048
extern const unsigned short testbackgroundMap[1024];

#define testbackgroundPalLen 512
extern const unsigned short testbackgroundPal[256];

#endif // GRIT_TESTBACKGROUND_H

//}}BLOCK(testbackground)
