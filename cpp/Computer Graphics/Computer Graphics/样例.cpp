//bool CalculateControlPoint(
//	const std::vector<Point2D>& rawPointVector,
//	std::vector<Point2D>& firstControlPointVector,
//	std::vector<Point2D>& secondControlPointVector)
//{
//	if (rawPointVector.size() < 2)
//	{
//		printf("输入点至少是2个\n");
//		return false;
//	}
//	std::size_t nPointSize = rawPointVector.size() - 1;
//	const Point2D* pRawPoint = rawPointVector.data();
//	if (1 == nPointSize)
//	{
//		// 特殊情况: 贝塞尔曲线是直线.
//
//		// 3P1 = 2P0 + P3
//
//		firstControlPointVector.resize(1);
//		firstControlPointVector[0].X = (2 * pRawPoint[0].X + pRawPoint[1].X) / 3;
//		firstControlPointVector[0].Y = (2 * pRawPoint[0].Y + pRawPoint[1].Y) / 3;
//		// P2 = 2P1 – P0
//		secondControlPointVector.resize(1);
//		secondControlPointVector[0].X = 2 * firstControlPointVector[0].X - pRawPoint[0].X;
//		secondControlPointVector[0].Y = 2 * firstControlPointVector[0].Y - pRawPoint[0].Y;
//		return true;
//	}
//
//	std::vector<double> rhs(nPointSize);
//	double* pTmp = rhs.data();
//	for (std::size_t i = 1; i < nPointSize - 1; ++i)
//	{
//		pTmp[i] = 4 * pRawPoint[i].X + 2 * pRawPoint[i + 1].X;
//	}
//	pTmp[0] = pRawPoint[0].X + 2 * pRawPoint[1].X;
//	pTmp[nPointSize - 1] = (8 * pRawPoint[nPointSize - 1].X + pRawPoint[nPointSize].X) / 2.0;
//
//	std::vector<double> x;
//	GetFirstControlPoints(rhs, x);
//
//	for (std::size_t i = 1; i < nPointSize - 1; ++i)
//		pTmp[i] = 4 * pRawPoint[i].Y + 2 * pRawPoint[i + 1].Y;
//	pTmp[0] = pRawPoint[0].Y + 2 * pRawPoint[1].Y;
//	pTmp[nPointSize - 1] = (8 * pRawPoint[nPointSize - 1].Y + pRawPoint[nPointSize].Y) / 2.0;
//
//	std::vector<double> y;
//	GetFirstControlPoints(rhs, y);
//	double* pX = x.data();
//	double* pY = y.data();
//
//	firstControlPointVector.resize(nPointSize);
//	secondControlPointVector.resize(nPointSize);
//	Point2D* pFirstPoints = firstControlPointVector.data();
//	Point2D* pSecondPoints = secondControlPointVector.data();
//	for (std::size_t i = 0; i < nPointSize; ++i)
//	{
//		// Second control point
//		pFirstPoints[i].X = x[i];
//		pFirstPoints[i].Y = y[i];
//		if (i < nPointSize - 1)
//		{
//			pSecondPoints[i].X = 2 * pRawPoint[i + 1].X - pX[i + 1];
//			pSecondPoints[i].Y = 2 * pRawPoint[i + 1].Y - pY[i + 1];
//		}
//		else
//		{
//			pSecondPoints[i].X = (pRawPoint[nPointSize].X + pX[nPointSize - 1]) / 2;
//			pSecondPoints[i].Y = (pRawPoint[nPointSize].Y + pY[nPointSize - 1]) / 2;
//		}
//	}
//
//	return true;
//}
