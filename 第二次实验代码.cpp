// CMFCApplication1View 绘制
void CMFCApplication1View::DDALine(int x0, int y0, int x1, int y1, CDC*pDC)
{
	int dx, dy, epsl, k;
	float x, y, xIncre, yIncre;
	dx = x1 - x0;  dy = y1 - y0;
	x = x0; y = y0;
	if (abs(dx) > abs(dy)) epsl = abs(dx);
	else epsl = abs(dy);
	xIncre = (float)dx / (float)epsl;
	yIncre = (float)dy / (float)epsl;
	for (k = 0; k <= epsl; k++){
		pDC->SetPixel(int(x + 0.5), (int)(y + 0.5), RGB(10, 10, 30));
		x += xIncre;
		y += yIncre;

	}
}
void CMFCApplication1View:: MidBresenhamLine(int x0, int y0, int x1, int y1, CDC *pDC)
{

	int dx, dy, d, UpIncre, DownIncre, x, y;
	if (x0>x1)
	{
		x = x1; x1 = x0; x0 = x;
		y = y1; y1 = y0; y0 = y;
	}
	x = x0; y = y0;
	dx = x1 - x0; dy = y1 - y0;
	d = dx - 2 * dy;
	UpIncre = 2 * dx - 2 * dy; DownIncre = -2 * dy;
	while (x <= x1){
		pDC->SetPixel(x, y, RGB(250, 0, 0));
		x++;
		if (d<0){
			y++;
			d += UpIncre;

		}
		else d += DownIncre;
	}
}
void CMFCApplication1View:: BresenhamLine(int x0, int y0, int x1, int y1, CDC *pDC)
{
	int x, y, dx, dy, e;
	dx = x1 - x0;
	dy = y1 - y0;
	e = -dx; x = x0; y = y0;
	while (x <= x1){
		pDC->SetPixel(x, y, RGB(250, 0, 0));
		x++;
		e = e + 2 * dy;
		if (e>0){
			y++;
			e = e - 2 * dx;
		}
	}

}
void CMFCApplication1View::MidBresenhamCircle(int r, CDC *pDC)
{
	int x, y, d;
	x = 0; y = r; d = 1 - r;
	while (x <= y){
		pDC->SetPixel(x, y, RGB(250, 0, 0));   pDC->SetPixel(y, x, RGB(250, 0, 0));
		pDC->SetPixel(-y, x, RGB(250, 0, 0));  pDC->SetPixel(-x, y, RGB(250, 0, 0));

		pDC->SetPixel(-x, -y, RGB(250, 0, 0));  pDC->SetPixel(-y, -x, RGB(250, 0, 0));
		pDC->SetPixel(y, -x, RGB(250, 0, 0));   pDC->SetPixel(x, -y, RGB(250, 0, 0));
		if (d<0) d += 2 * x + 3;
		else {
			d += 2 * (x - y) + 5;
			y--;
		}
		x++;
	}

}
void CMFCApplication1View::MidBresenhamEllipse(int a, int b, CDC *pDC)
{
	int x, y;
	float d1, d2;
	x = 0; y = b;
	d1 = b*a + a*a*(-b + 0.25);
	pDC->SetPixel(x, y, RGB(50, 0, 0));
	pDC->SetPixel(-x, -y, RGB(50, 0, 0));
	pDC->SetPixel(-x, y, RGB(50, 0, 0));
	pDC->SetPixel(x, -y, RGB(50, 0, 0));
	while (b*b*(x + 1)<a*a*(y - 0.5)){
		if (d1 <= 0){
			d1 += b*b*(2 * x + 3);
			x++;
		}
		else{
			d1 += b*b*(2 * x + 3) + a*a*(-2 * y + 2);
			x++; y--;
		}
		pDC->SetPixel(x, y, RGB(50, 0, 0));
		pDC->SetPixel(-x, -y, RGB(50, 0, 0));
		pDC->SetPixel(-x, y, RGB(50, 0, 0));
		pDC->SetPixel(x, -y, RGB(50, 0, 0));
	}/*while上半部分*/
	d2 = b*b*(x + 0.5)*(x + 0.5) + a*a*(y - 1)*(y - 1) - a*a*b*b;
	while (y>0){
		if (d2 <= 0){
			d2 += b*b*(2 * x + 2) + a*a*(-2 * y + 3);
			x++; y--;
		}
		else{
			d2 += a*a*(-2 * y + 3);
			y--;
		}
		pDC->SetPixel(x, y, RGB(50, 0, 0));
		pDC->SetPixel(-x, -y, RGB(50, 0, 0));
		pDC->SetPixel(-x, y, RGB(50, 0, 0));
		pDC->SetPixel(x, -y, RGB(50, 0, 0));
	}
}
void CMFCApplication1View::MidBresenhamCircle(int r, int dx, int dy, CDC *pDC)
{
	int x, y, d;
	x = 0; y = r; d = 1 - r;
	while (x <= y){
		pDC->SetPixel(x + dx, y + dy, RGB(50, 0, 0));   pDC->SetPixel(y + dx, x + dy, RGB(50, 0, 0));
		pDC->SetPixel(-y + dx, x + dy, RGB(50, 0, 0));  pDC->SetPixel(-x + dx, y + dy, RGB(50, 0, 0));
		pDC->SetPixel(-x + dx, -y + dy, RGB(50, 0, 0));  pDC->SetPixel(-y + dx, -x + dy, RGB(50, 0, 0));
		pDC->SetPixel(y + dx, -x + dy, RGB(50, 0, 0));   pDC->SetPixel(x + dx, -y + dy, RGB(50, 0, 0));
		if (d<0) d += 2 * x + 3;
		else{
			d += 2 * (x - y) + 5;
			y--;
		}
		x++;
	}
}
void CMFCApplication1View::MidBresenhamEllipse(int a, int b, int dx, int dy, CDC *pDC)
{
	int x, y;
	float d1, d2;
	x = 0; y = b;
	d1 = b*a + a*a*(-b + 0.25);
	pDC->SetPixel(x + dx, y + dy, RGB(255, 0, 0));
	pDC->SetPixel(-x + dx, -y + dy, RGB(255, 0, 0));
	pDC->SetPixel(-x + dx, y + dy, RGB(255, 0, 0));
	pDC->SetPixel(x + dx, -y + dy, RGB(255, 0, 0));
	while (b*b*(x + 1)<a*a*(y - 0.5)){
		if (d1 <= 0){
			d1 += b*b*(2 * x + 3);
			x++;
		}
		else{
			d1 += b*b*(2 * x + 3) + a*a*(-2 * y + 2);
			x++; y--;
		}
		pDC->SetPixel(x + dx, y + dy, RGB(255, 0, 0));
		pDC->SetPixel(-x + dx, -y + dy, RGB(255, 0, 0));
		pDC->SetPixel(-x + dx, y + dy, RGB(255, 0, 0));
		pDC->SetPixel(x + dx, -y + dy, RGB(255, 0, 0));
	}/*while上半部分*/
	d2 = b*b*(x + 0.5)*(x + 0.5) + a*a*(y - 1)*(y - 1) - a*a*b*b;
	while (y>0){
		if (d2 <= 0){
			d2 += b*b*(2 * x + 2) + a*a*(-2 * y + 3);
			x++; y--;
		}
		else{
			d2 += a*a*(-2 * y + 3);
			y--;
		}
		pDC->SetPixel(x + dx, y + dy, RGB(255, 0, 0));
		pDC->SetPixel(-x + dx, -y + dy, RGB(255, 0, 0));
		pDC->SetPixel(-x + dx, y + dy, RGB(255, 0, 0));
		pDC->SetPixel(x + dx, -y + dy, RGB(255, 0, 0));
	}
}
void CMFCApplication1View::OnDraw(CDC* pDC)
{
	CMFCApplication1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDC->SetMapMode(4);
	CRect rc;
	GetClientRect(&rc);
	pDC->SetViewportOrg(rc.right / 2, rc.bottom / 2);
	pDC->MoveTo(-rc.right, 0);
	pDC->LineTo(rc.right, 0);
	pDC->MoveTo(0, rc.bottom);
	pDC->LineTo(0, -rc.bottom);//将坐标系平移至屏幕中心

	DDALine(200, 100, 800, 500, pDC);//DDA画直线
	MidBresenhamLine(-300, 200, -50, 660, pDC);//中点Bresenham画直线
	BresenhamLine(300, -200, 800, -100, pDC);//Bresenham画直线
	MidBresenhamCircle(100, pDC);
	MidBresenhamEllipse(200, 100, -200, -200, pDC);//中点Bresenham画椭圆并平移到第三象
	if (!pDoc)

		return;

	// TODO:  在此处为本机数据添加绘制代码
