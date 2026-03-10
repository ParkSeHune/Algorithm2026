#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

using namespace std;
using namespace sf;

class Complexity
{
private:
	VertexArray m_graphLinear; // O(N)
	VertexArray m_graphQuadratic; // O(N^2)
	VertexArray m_axes; // x, y axis

	//축의 시작 좌표와 길이
	const float START_X = 50.f;
	const float START_Y = 550.f;
	const float X_WIDTH = 700.f;
	const float Y_HEIGT = 500.f;

public:
	Complexity()
	{
		m_graphLinear.setPrimitiveType(LinesStrip);
		m_graphQuadratic.setPrimitiveType(LineStrip);
		m_axes.setPrimitiveType(Lines);

		setupAxes();
	}

	void setupAxes()
	{
		//y axis
		m_axes.append(Vertex(Vector2f(START_X, START_Y), Color::White));
		m_axes.append(Vertex(Vector2f(START_X, START_Y - Y_HEIGT), Color::White));

		//x axis
		m_axes.append(Vertex(Vector2f(START_X, START_Y), Color::White));
		m_axes.append(Vertex(Vector2f(START_X + X_WIDTH, START_Y), Color::White));
	}

	void linearAlgorithm(int N)
	{
		volatile int sum = 0;
		for (int i = 0; i < N; i++)
		{
			sum += i; 
			for (int k = 0; k < 500; k++)
			{
				sum++;
			}
		}
	}

	void quadraticAlgorithm(int N)
	{
		volatile int sum = 0;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				sum += (i + j);
			}
		}
	}

	void runAlgorithm(int startN, int endN, int step)
	{
		cout << "Starting perfomance test (" << startN << " to " << endN << ")" << endl << endl;

		m_graphLinear.clear();
		m_graphQuadratic.clear();
		for (int N = startN; N < endN; N += step)
		{
			Clock clock;
			Time time;

			//linearAlgorithm O(N)
			clock.restart();
			linearAlgorithm(N);
			time = clock.getElapsedTime();
			float timeLinear = time.asSeconds();

			//quadraticAlgorithm O(N^2)
			clock.restart();
			quadraticAlgorithm(N);
			time = clock.getElapsedTime();
			float timeQuadratic = time.asSeconds();

			float xBatio = (float)(N - startN) / (float)(endN - startN);
			float x = START_X + xBatio * X_WIDTH;

			//시간 증폭
			float timeScale = 4000.f;
			float yLinear = START_Y - (timeScale * timeLinear);
			float yQuadratic = START_Y - (timeScale * timeQuadratic);

			m_graphLinear.append(Vertex(Vector2f(x, yLinear), Color::Green));
			m_graphQuadratic.append(Vertex(Vector2f(x, yQuadratic), Color::Red));
		}

		cout << "Test Completed" << endl;
	}

	void draw(RenderWindow& win)
	{
		win.draw(m_axes);
		win.draw(m_graphLinear);
		win.draw(m_graphQuadratic);
	}
};

