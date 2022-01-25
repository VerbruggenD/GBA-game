
//{{BLOCK(Crops)

//======================================================================
//
//	Crops, 32x224@8, 
//	+ palette 256 entries, not compressed
//	+ 77 tiles (t|f|p reduced) not compressed
//	+ regular map (flat), not compressed, 4x28 
//	Total size: 512 + 4928 + 224 = 5664
//
//	Time-stamp: 2022-01-25, 13:55:13
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.6
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_CROPS_H
#define GRIT_CROPS_H

#define CropsTilesLen 4928
extern const unsigned short CropsTiles[2464];

#define CropsMapLen 224
extern const unsigned short CropsMap[112];

#define CropsPalLen 512
extern const unsigned short CropsPal[256];

#endif // GRIT_CROPS_H

//}}BLOCK(Crops)
