//
// starBrush.h
//
// The header file for Point Brush. 
//

#ifndef STARBRUSH_H
#define STARBRUSH_H

#include "impBrush.h"

class StarBrush : public ImpBrush
{
public:
	StarBrush( ImpressionistDoc* pDoc = NULL, char* name = NULL );

	void BrushBegin( const Point source, const Point target );
	void BrushMove( const Point source, const Point target );
	void BrushEnd( const Point source, const Point target );
	char* BrushName( void );
};

#endif
