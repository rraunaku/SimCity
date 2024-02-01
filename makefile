sims: main.o simcity.o residential.o industrial.o commercial.o chernobyl.o hospital.o monster.o hero.o
	g++ main.o simcity.o residential.o industrial.o commercial.o chernobyl.o hospital.o monster.o hero.o -o sims

main.o: main.cpp
	g++ -c main.cpp

simcity.o: simcity.cpp
	g++ -c simcity.cpp

residential.o: residential.cpp
	g++ -c residential.cpp

industrial.o: industrial.cpp
	g++ -c industrial.cpp

commercial.o: commercial.cpp
	g++ -c commercial.cpp

pollution.o: pollution.cpp
	g++ -c pollution.cpp

chernobyl.o: chernobyl.cpp
	g++ -c chernobyl.cpp

hospital.o: hospital.cpp
	g++ -c hospital.cpp

monster.o: monster.cpp
	g++ -c monster.cpp

hero.o: hero.cpp
	g++ -c hero.cpp
clean:
	rm *.o sims