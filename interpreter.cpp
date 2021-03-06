#include "interpreter.h"

Interpreter::Interpreter(string filename)
{
	ifstream file(filename);
	string line;
	while (getline(file, line))
	{
		if (line.substr(0, 1) == "v")
		{
			vector<GLfloat> Point;
			GLfloat x, y, z;
			istringstream s(line.substr(2));
			s >> x; s >> y; s >> z;
			Point.push_back(x);
			Point.push_back(y);
			Point.push_back(z);
			v.push_back(Point);
		}
		if (line.substr(0, 1) == "f")
		{
			vector<GLint> vIndexSets;
			GLint u, v, w;
			istringstream vtns(line.substr(2));
			vtns >> u; vtns >> v; vtns >> w;
			vIndexSets.push_back(u - 1);
			vIndexSets.push_back(v - 1);
			vIndexSets.push_back(w - 1);
			f.push_back(vIndexSets);
		}
	}
	file.close();
}

void Interpreter::DrawT()
{
	// turn on texture mode
	glEnable(GL_TEXTURE_2D);
	glBegin(GL_TRIANGLES);//Start drawing
	for (int i = 0; i < f.size(); i++)
	{
		//Three vertices
		vertex a, b, c;
		GLint firstVertexIndex = (f[i])[0];//Remove the vertex index
		GLint secondVertexIndex = (f[i])[1];
		GLint thirdVertexIndex = (f[i])[2];

		a.x = (v[firstVertexIndex])[0];//The first vertex
		a.y = (v[firstVertexIndex])[1];
		a.z = (v[firstVertexIndex])[2];

		b.x = (v[secondVertexIndex])[0]; //The second vertex
		b.y = (v[secondVertexIndex])[1];
		b.z = (v[secondVertexIndex])[2];

		c.x = (v[thirdVertexIndex])[0]; //The third vertex
		c.y = (v[thirdVertexIndex])[1];
		c.z = (v[thirdVertexIndex])[2];

		glTexCoord2f(0.0, 0.0);	//texturing
		glVertex3f(a.x, a.y, a.z);//Draw triangle
		glTexCoord2f(1.0, 0.0);
		glVertex3f(b.x, b.y, b.z);
		glTexCoord2f(0.0, 1.0);
		glVertex3f(c.x, c.y, c.z);
	}
	glEnd();
	glDisable(GL_TEXTURE_2D); // turn of texture mode
}

void Interpreter::Draw()
{
	glBegin(GL_TRIANGLES);//Start drawing
	for (int i = 0; i < f.size(); i++)
	{
		//Three vertices
		vertex a, b, c;
		GLint firstVertexIndex = (f[i])[0];//Remove the vertex index
		GLint secondVertexIndex = (f[i])[1];
		GLint thirdVertexIndex = (f[i])[2];

		a.x = (v[firstVertexIndex])[0];//The first vertex
		a.y = (v[firstVertexIndex])[1];
		a.z = (v[firstVertexIndex])[2];

		b.x = (v[secondVertexIndex])[0]; //The second vertex
		b.y = (v[secondVertexIndex])[1];
		b.z = (v[secondVertexIndex])[2];

		c.x = (v[thirdVertexIndex])[0]; //The third vertex
		c.y = (v[thirdVertexIndex])[1];
		c.z = (v[thirdVertexIndex])[2];

		glVertex3f(a.x, a.y, a.z);//Draw triangle
		glVertex3f(b.x, b.y, b.z);
		glVertex3f(c.x, c.y, c.z);

	}
	glEnd();
}

void Interpreter::DrawObj(float posX, float posY, float posZ)
{
	glBegin(GL_TRIANGLES);//Start drawing
	for (int i = 0; i < f.size(); i++)
	{
		//Three vertices
		vertex a, b, c;
		GLint firstVertexIndex = (f[i])[0];//Remove the vertex index
		GLint secondVertexIndex = (f[i])[1];
		GLint thirdVertexIndex = (f[i])[2];

		a.x = (v[firstVertexIndex])[0];//The first vertex
		a.y = (v[firstVertexIndex])[1];
		a.z = (v[firstVertexIndex])[2];

		b.x = (v[secondVertexIndex])[0]; //The second vertex
		b.y = (v[secondVertexIndex])[1];
		b.z = (v[secondVertexIndex])[2];

		c.x = (v[thirdVertexIndex])[0]; //The third vertex
		c.y = (v[thirdVertexIndex])[1];
		c.z = (v[thirdVertexIndex])[2];

		//Draw triangles with corrected positions
		glVertex3f(a.x + posX, a.y + posY, a.z + posZ);
		glVertex3f(b.x + posX, b.y + posY, b.z + posZ);
		glVertex3f(c.x + posX, c.y + posY, c.z + posZ);
	}
	glEnd();
}


void Interpreter::DrawG()
{
	glBegin(GL_TRIANGLES);//Start drawing
	for (int i = 0; i < f.size(); i++)
	{
		//Three vertices
		vertex a, b, c;
		GLint firstVertexIndex = (f[i])[0];//Remove the vertex index
		GLint secondVertexIndex = (f[i])[1];
		GLint thirdVertexIndex = (f[i])[2];

		a.x = (v[firstVertexIndex])[0];//The first vertex
		a.y = (v[firstVertexIndex])[1];
		a.z = (v[firstVertexIndex])[2];

		b.x = (v[secondVertexIndex])[0]; //The second vertex
		b.y = (v[secondVertexIndex])[1];
		b.z = (v[secondVertexIndex])[2];

		c.x = (v[thirdVertexIndex])[0]; //The third vertex
		c.y = (v[thirdVertexIndex])[1];
		c.z = (v[thirdVertexIndex])[2];

		glColor3f(0.85, 0.78, 0.78);
		glVertex3f(a.x, a.y, a.z);//Draw triangle
		glColor3f(0.57, 0.45, 0.45);
		glVertex3f(b.x, b.y, b.z);
		glColor3f(0.95, 0.87, 0.87);
		glVertex3f(c.x, c.y, c.z);

	}
	glEnd();
}