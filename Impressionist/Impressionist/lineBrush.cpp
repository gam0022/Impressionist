//
// lineBrush.cpp
//
// The implementation of Point Brush. It is a kind of ImpBrush. All your brush implementations
// will look like the file with the different GL primitive calls.
//

#include "impressionistDoc.h"
#include "impressionistUI.h"
#include "lineBrush.h"
#include <math.h>

#define PI 3.1415

extern float frand();

LineBrush::LineBrush( ImpressionistDoc* pDoc, char* name ) :
	ImpBrush(pDoc,name)
{
}

void LineBrush::BrushBegin( const Point source, const Point target )
{
	ImpressionistDoc* pDoc = GetDocument();
	ImpressionistUI* dlg=pDoc->m_pUI;

	int size = pDoc->getSize();
	

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glPointSize( (float)size );

	BrushMove( source, target );
}

void LineBrush::BrushMove( const Point source, const Point target )
{
	ImpressionistDoc* pDoc = GetDocument();
	ImpressionistUI* dlg=pDoc->m_pUI;

	//�X���C�_�[��������

	if ( pDoc == NULL ) {
		printf( "LineBrush::BrushMove  document is NULL\n" );
		return;
	}

	int size=pDoc->getSize();
	int angle=pDoc->getAngle();	// �X���iAngle�j���擾
	int width=pDoc->getWidth();	// haba�iWidth�j���擾
	float alpha = pDoc->getAlpha() / 100.0;

	float Ax,Ay,Bx,By;
	Ax=target.x+size*cos(PI*angle/180);
	Ay=target.y+size*sin(PI*angle/180);
	Bx=target.x-size*cos(PI*angle/180);
	By=target.y-size*sin(PI*angle/180);

	glLineWidth(width);
	glLineStipple(1, 0xaaaa);
	glEnable(GL_LINE_STIPPLE);

	glBegin(GL_LINES);		// ����`��
		SetColorAlpha( source, alpha );
		glVertex2f(Ax,Ay);
		glVertex2f(Bx,By);
	glEnd();

	glDisable(GL_LINE_STIPPLE);
}

void LineBrush::BrushEnd( const Point source, const Point target )
{
	// do nothing so far
	glDisable(GL_BLEND);

}

