#include "Canvas.h"
#include <stdio.h>

Canvas::Canvas(int width, int height)
{
	this->width = width;
	this->height = height;
	Clear();
}

void Canvas::DrawCircle(int x, int y, int ray, char ch)
{
	for (int i = 0; i < this->height; i ++)
		for (int j = 0; j < this->width; j ++)
		{
			float d = (i - x) * (i - x) + (j - y) * (j - y);
			float val = ray - 0; // -2
			if (d <= ray * ray && d + val >= ray * ray)
				SetPoint(i, j, ch);
			if (d >= ray * ray && d - val <= ray * ray)
				SetPoint(i, j, ch);
		}
}

void Canvas::FillCircle(int x, int y, int ray, char ch)
{
	for (int i = 0; i < this->width; i++)
		for (int j = 0; j < this->height; j++)
			if ((i - x) * (i - x) + (j - y) * (j - y)  <= ray * ray)
				SetPoint(i, j, ch);
}

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch)
{
	for (int i = left; i <= right; i++)
	{
		SetPoint(top, i, ch);
		SetPoint(bottom, i, ch);
	}
	for(int i = top; i <= bottom; i++)
	{
		SetPoint(i, left, ch);
		SetPoint(i, right, ch);
	}
}

void Canvas::FillRect(int left, int top, int right, int bottom, char ch)
{
	for (int i = top; i <= bottom; i++)
		for (int j = left; j <= right; j++)
			SetPoint(i, j, ch);
}

void Canvas::SetPoint(int x, int y, char ch)
{
	this->a[x][y] = ch;
}
void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch)
{
	float dx = x1 - x2;
	float dy = y1 - y2;
	float d = dx / dy;
	if (d < 0)
		d = -d;
	float error = 0.0;
	int y = y1;
	for (int x = x1; x <= x2; x++)
	{
		SetPoint(x, y, ch);
		error += d;
		if (error >= 0.5)
		{
			if (dy < 0)
				y = y + 1.0;
			else
				if (dy > 0)
					y = y - 1.5;
			error--;
		}
	}
}

void Canvas::Print()
{
	for (int i = 0; i < this->width; ++i)
	{
		for (int j = 0; j < this->height; ++j)
			printf("%c ", this->a[i][j]);
		printf("\n");
	}
}

void Canvas::Clear()
{
	for (int i = 0; i < this->height; ++i)
		for (int j = 0; j < this->width; j++)
			this->a[i][j] = ' ';
}