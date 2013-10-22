//
// starBrush.cpp
//
// The implementation of Point Brush. It is a kind of ImpBrush. All your brush implementations
// will look like the file with the different GL primitive calls.
//

#include "impressionistDoc.h"
#include "impressionistUI.h"
#include "starBrush.h"
#include <math.h>
#define PI 3.1415

extern float frand();

StarBrush::StarBrush( ImpressionistDoc* pDoc, char* name ) :
	ImpBrush(pDoc,name)
{
}

void StarBrush::BrushBegin( const Point source, const Point target )
{
	ImpressionistDoc* pDoc = GetDocument();
	ImpressionistUI* dlg=pDoc->m_pUI;

	int size = pDoc->getSize();
	

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glPointSize( (float)size );

	BrushMove( source, target );
}

void StarBrush::BrushMove( const Point source, const Point target )
{
	ImpressionistDoc* pDoc = GetDocument();
	ImpressionistUI* dlg=pDoc->m_pUI;

	//スライダーつけたあと

	if ( pDoc == NULL ) {
		printf( "StarBrush::BrushMove  document is NULL\n" );
		return;
	}

	int size    = pDoc->getSize();
	int width   = pDoc->getWidth();
	int angle   = pDoc->getAngle();
	float alpha = pDoc->getAlpha() / 100.0;

	SetColorAlpha( source, alpha );

	float Ax, Ay, Bx, By, Cx, Cy;
	float r1 = size * 2;
	float r2 = size;
	float dr = PI * angle / 180;

	glBegin(GL_TRIANGLE_STRIP);
	for (int i=0; i<5; i++){
		Ax = target.x + r2*sin(2*M_PI*2*i/10 + dr);
		Ay = target.y + r2*cos(2*M_PI*2*i/10 + dr);
		Bx = target.x + r1*sin(2*M_PI*(2*i+1)/10 + dr);
		By = target.y + r1*cos(2*M_PI*(2*i+1)/10 + dr);
		Cx = target.x + r2*sin(2*M_PI*(2*i+2)/10 + dr);
		Cy = target.y + r2*cos(2*M_PI*(2*i+2)/10 + dr);
		glVertex2d(target.x , target.y);
		glVertex2f(Ax, Ay);
		glVertex2f(Bx, By);
		glVertex2d(target.x , target.y);
		glVertex2f(Bx, By);
		glVertex2f(Cx, Cy);
	}
	glEnd();
}

void StarBrush::BrushEnd( const Point source, const Point target )
{
	// do nothing so far
	glDisable(GL_BLEND);

}

