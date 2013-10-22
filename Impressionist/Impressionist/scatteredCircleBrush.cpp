//
// scatteredScatteredCircleBrush.cpp
//
// The implementation of Point Brush. It is a kind of ImpBrush. All your brush implementations
// will look like the file with the different GL primitive calls.
//

#include "impressionistDoc.h"
#include "impressionistUI.h"
#include "scatteredCircleBrush.h"
#include <math.h>
#define PI 3.1415

extern float frand();

ScatteredCircleBrush::ScatteredCircleBrush( ImpressionistDoc* pDoc, char* name ) :
	ImpBrush(pDoc,name)
{
}

void ScatteredCircleBrush::BrushBegin( const Point source, const Point target )
{
	ImpressionistDoc* pDoc = GetDocument();
	ImpressionistUI* dlg=pDoc->m_pUI;

	int size = pDoc->getSize();
	

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glPointSize( (float)size );

	BrushMove( source, target );
}

void ScatteredCircleBrush::BrushMove( const Point source, const Point target )
{
	ImpressionistDoc* pDoc = GetDocument();
	ImpressionistUI* dlg=pDoc->m_pUI;

	//スライダーつけたあと

	if ( pDoc == NULL ) {
		printf( "ScatteredCircleBrush::BrushMove  document is NULL\n" );
		return;
	}

	int size    = pDoc->getSize();
	int width   = pDoc->getWidth();
	int angle   = pDoc->getAngle();
	float alpha = pDoc->getAlpha() / 100.0;
	int Ax,Ay;

	for(int i=0;i<10;i++){
		Ax=target.x-size/2+rand()%size;
		Ay=target.y-size/2+rand()%size;
		int div = 12;
		float radius = width;
		float Bx,By;
		glBegin(GL_POLYGON);
		SetColorAlpha( source, alpha );
		for(int j=0;j<div;j++){
			Bx = Ax + radius*cos(2*PI*j/div);
			By = Ay + radius*sin(2*PI*j/div);
			glVertex2f(Bx,By);	 //float型で引数指定
		}
		glEnd();
	}
}

void ScatteredCircleBrush::BrushEnd( const Point source, const Point target )
{
	// do nothing so far
	glDisable(GL_BLEND);

}

