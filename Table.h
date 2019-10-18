#ifndef __TABLE_2019__
#define __TABLE_2019__

class Table {
	bool** field; // ������� ����, ������ ������� �������� 0 ��� 1
	int cols, rows;

public:
	Table(): cols(0), rows(0), field(nullptr) {}

	Table(int col, int row, bool** f): cols(col), rows(row) {
		rows += 2;
		cols += 2;

		//��������� ������ ��� �������
		field = new bool*[rows];
		for (int i = 0; i < rows; ++i)
			field[i] = new bool[cols];

		//���������� ������, ����� ������� ���� �����������(�������)
		for (int i = 1; i < rows - 1; ++i) { field[i][0] = f[i - 1][cols - 3]; field[i][cols - 1] = f[i - 1][0]; }
		for (int i = 1; i < cols - 1; ++i) { field[0][i] = f[rows - 3][i - 1]; field[rows - 1][i] = f[0][i - 1]; }
		field[0][0] = f[rows - 3][cols - 3]; field[0][cols - 1] = f[rows - 3][0];
		field[rows - 1][0] = f[0][cols - 3]; field[rows - 1][cols - 1] = f[0][0];
		//----------------------------------------------------------

		//����������� ��������� ���� � field
		for (int i = 1; i < rows - 1; ++i)
			for (int j = 1; j < cols - 1; ++j)
				field[i][j] = f[i - 1][j - 1];
		//----------------
	}

	void operator=(const Table& table){

		for (int i = 0; i < rows; ++i)
			delete[] field[i];
		delete[] field;

		this->cols = table.cols;
		this->rows = table.rows;

		field = new bool*[rows];
		for (int i = 0; i < rows; ++i)
			field[i] = new bool[cols];
		
		for (int i = 0; i < rows; ++i)
			for (int j = 0; j < cols; ++j)
				this->field[i][j] = table.field[i][j];
	}

	~Table() {
		//������� ������ ����
		for (int i = 0; i < rows; ++i)
			delete[] field[i];
		delete[] field;
	}

	// ������� ������ ������� ����, ������ ���� '0' �� '_' � ���� 1 �� 'O'
	const void printField() const{
		for (int i = 1; i < rows - 1; ++i) {
			std::cout << "\t";
			for (int j = 1; j < cols - 1; ++j) {
				if (field[i][j] == 0) std::cout << '_';
				else std::cout << 'O';
			}
			std::cout << std::endl;
		}
	}

	// ������� � ���������� ���������, ��������� �� ���� �������, ������� ������� � � ����������� �� �� ����������
	// �������� ���� (������ ���� �������� � ������� cloneField)
	// ������� ����� ��������� ��������� �� ���������� ��������� � �����, ���� ��, ���������� True
	bool nextGeneration() {
		bool** cloneField = new bool*[rows];
		bool theEnd = true;
		for (int i = 0; i < rows; ++i) cloneField[i] = new bool[cols];
		for (int i = 0; i < rows; ++i)
			for (int j = 0; j < cols; ++j)
				cloneField[i][j] = field[i][j];

		//������� ���� �� ���� ��������� �������
		for(int i = 1; i < rows - 1; ++i) {
			for (int j = 1; j < cols - 1; ++j) {
				int neighbors = cloneField[i - 1][j - 1] + cloneField[i - 1][j] + cloneField[i - 1][j + 1]
								+ cloneField[i][j - 1] + cloneField[i][j + 1]
								+ cloneField[i + 1][j - 1] + cloneField[i + 1][j] + cloneField[i + 1][j + 1];
				if (neighbors == 3 && cloneField[i][j] == 0) { // ���� ������ ������� � � ��� ��� ����� ������,
					field[i][j] = 1;						   // �� �������� ������
					theEnd = false; // ���� ���� ��� �� ����������, ������ ��������� ���������� � ���� ������������
				}
				if (cloneField[i][j] == 1 && (neighbors < 2 || neighbors > 3)) { // ��������� ����� ������
					field[i][j] = 0;											
					theEnd = false; // ���� ���� ��� �� ����������, ������ ��������� ���������� � ���� ������������
				}
			}
		}
		//--------------------------------------

		//��������� ������ ���� ��� ������ ���������
		for (int i = 1; i < rows - 1; ++i) { field[i][0] = field[i][cols - 2]; field[i][cols - 1] = field[i][1]; }
		for (int i = 1; i < cols - 1; ++i) { field[0][i] = field[rows - 2][i]; field[rows - 1][i] = field[1][i]; }
		field[0][0] = field[rows - 2][cols - 2]; field[0][cols - 1] = field[rows - 2][1];
		field[rows - 1][0] = field[1][cols - 2]; field[rows - 1][cols - 1] = field[1][1];
		//------------------------------------------

		return theEnd;
	}

	// ������� �������� ����� ������
	int countOfAlive() {
		int cnt = 0;
		for (int i = 1; i < rows - 1; ++i) {
			for (int j = 1; j < cols - 1; ++j) {
				if (field[i][j]) ++cnt;
			}
		}
		return cnt;
	}
};

#endif

