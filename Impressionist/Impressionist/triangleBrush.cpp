//
// triangleBrush.cpp
//
// The implementation of Point Brush. It is a kind of ImpBrush. All your brush implementations
// will look like the file with the different GL primitive calls.
//

#include "impressionistDoc.h"
#include "impressionistUI.h"
#include "triangleBrush.h"

extern float frand();

TriangleBrush::TriangleBrush( ImpressionistDoc* pDoc, char* name ) :
	ImpBrush(pDoc,name)
{
}

void TriangleBrush::BrushBegin( const Point source, const Point target )
{
	ImpressionistDoc* pDoc = GetDocument();
	ImpressionistUI* dlg=pDoc->m_pUI;

	int size = pDoc->getSize();
	

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glPointSize( (float)size );

	BrushMove( source, target );
}

void TriangleBrush::BrushMove( const Point source, const Point target )
{
	ImpressionistDoc* pDoc = GetDocument();
	ImpressionistUI* dlg=pDoc->m_pUI;

	//スライダーつけたあと

	if ( pDoc == NULL ) {
		printf( "TriangleBrush::BrushMove  document is NULL\n" );
		return;
	}

	//SetColorAlpha( source, alpha );
	//SetColor( source );
	//glBegin( GL_POINTS );
	//glVertex2d( target.x, target.y );
	//glEnd();

	//ダイアログのスライダーからブラシの大きさを取得
	int size = pDoc->getSize();
	int Ax,Ay,Bx,By,Cx,Cy;

	//三角形の各頂点の座標
	Ax = target.x - (.5*size);
	Bx = target.x + (.5*size);
	Cx = target.x;
	Ay = target.y - (.5*size);
	By = target.y - (.5*size);
	Cy = target.y + (.5*size);

	//引数がGL_POLYGONの場合、凸多角形を描画
	glBegin(GL_POLYGON);
	SetColor( source );
	glVertex2i( Ax, Ay );
	glVertex2i( Bx, By );
	glVertex2i( Cx, Cy );
	glEnd();
}

void TriangleBrush::BrushEnd( const Point source, const Point target )
{
	// do nothing so far
	glDisable(GL_BLEND);

}

