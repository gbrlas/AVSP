#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>



class Map
{
	private:
		size_t m_W;
		size_t m_H;
		struct Sector
		{
			int att;
			char label;
			Sector* north;
			Sector* west;
			Sector* east;
			Sector* south;
		};
		std::vector<Sector> m_map;
		Sector* GetDown(Sector* s) const;
	public:
		Map(size_t W,size_t H);
		void Set(size_t x,size_t y,int val);
		
		char Get(size_t x,size_t y) const;
		
		void Calc();

		void print();
		void print_res();
};

Map::Map(size_t W,size_t H) : m_W(W),m_H(H) {
	m_map.resize(W*H);
	for (size_t y=0;y<H;y++) {
		for (size_t x=0;x<W;x++) {
			Sector& s = m_map[y*W+x];
			s.label='.';
			s.north = (y>0) ? &m_map[(y-1)*W+x] : 0;
			s.west = (x>0) ? &m_map[y*W+x-1] : 0;
			s.east = (x<(W-1)) ? &m_map[y*W+x+1] : 0;
			s.south = (y<(H-1)) ? &m_map[(y+1)*W+x] : 0;
		}
	}
}
void Map::Set(size_t x,size_t y,int val) 
{
	m_map[x+y*m_W].att=val;
}
char Map::Get(size_t x,size_t y) const
{
	return m_map[x+y*m_W].label;
}

Map::Sector* Map::GetDown(Map::Sector* s) const {
	Sector* crnt = s;
	while (true) 
	{
		Sector* min = crnt;	
		if (crnt->north && crnt->north->att < min->att) {
			min = crnt->north;
		} 
		if (crnt->west && crnt->west->att < min->att) {
			min = crnt->west;
		}
		if (crnt->east && crnt->east->att < min->att) {
			min = crnt->east;
		}
		if (crnt->south && crnt->south->att < min->att) {
			min = crnt->south;
		}  
		if (min==crnt) break;
		crnt=min;
		if (crnt->label!='.') break;
	}
	return crnt;
}

void Map::Calc() 
{
	char label = 'a';
	m_map[0].label=label;
	for (size_t i=0;i<m_map.size();i++)
	{
		Sector* crnt = &m_map[i];
		Sector* s = GetDown(crnt);
		if ( s->label!='.') {
			crnt->label=s->label;
		} else 
		{
			if (crnt->label!='.')
				s->label=crnt->label;
			else {
				label++;
				crnt->label=label;
				s->label=crnt->label;
			}
		}
	}
}

void Map::print()
{
	for (size_t y=0;y<m_H;y++) {
		for (size_t x=0;x<m_W;x++) {
			std::cout << " " << m_map[x+y*m_W].att;
		}
		std::cout << std::endl;
	}
}

void Map::print_res()
{
	for (size_t y=0;y<m_H;y++) {
		for (size_t x=0;x<m_W;x++) {
			std::cout << m_map[x+y*m_W].label;
		}
		std::cout << std::endl;
	}
}

int main(int argc,char** argv)
{
	if (argc<3) {
		std::cout << "usage : " << argv[0] << " infile outfile" << std::endl;
		return 0;
	}
	std::ifstream in(argv[1]);
	if (!in) {
		std::cout << " error opening file " << argv[1] << std::endl;
		return 1;
	}
	std::ofstream out(argv[2]);
	if (!out) {
		std::cout << " error creating file " << argv[2] << std::endl;
		return 1;
	}
	size_t T;
	in >> T ;
	std::cout << "T=" << T << std::endl;
	for (size_t n = 0;n<T;n++) {
		size_t W;
		size_t H;
		in >> H >> W;
		Map map(W,H);
		for (size_t y=0;y<H;y++) {
			for (size_t x=0;x<W;x++) {
				int val;
				in >> val;
				map.Set(x,y,val);
			}
		}
		std::cout << "Map #"<<n+1<<std::endl;
		map.print();
		map.Calc();
		std::cout << "result" << std::endl;
		map.print_res();
		out << "Case #"<<n+1<<":" << std::endl;
		for (size_t y=0;y<H;y++) {
			for (size_t x=0;x<W;x++) {
				out << map.Get(x,y);
				if (x<(W-1)) out << " ";
			}
			out << std::endl;
		}
	}
	return 0;
}
