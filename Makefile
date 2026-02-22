# Makefile for Practical 1 Deployment

deploy: game.cpp right.htm wrong.htm
	g++ game.cpp -o game
	sudo cp right.htm wrong.htm /var/www/html/
	sudo cp game /usr/lib/cgi-bin/
	sudo chmod +x /usr/lib/cgi-bin/game
	@echo "Success! The latest version is now live on the server."