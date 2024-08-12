#include <cstdio>
#include <ftxui/component/component.hpp>
#include <ftxui/component/component_options.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/dom/elements.hpp>
#include <ftxui/dom/flexbox_config.hpp>
#include <ftxui/dom/node.hpp>
#include <string>

using namespace ftxui;

Element ColorTile(int red, int green, int blue) {
	return text("") | size(WIDTH, GREATER_THAN, 14) |
		size(HEIGHT, GREATER_THAN, 7) | bgcolor(Color::RGB(red, green, blue));
}

void songChange(){}

int main(){

	Elements aInfo = {text("Artist"), text("Name"), text("05:00")};
	Element aImage = ColorTile(255, 123, 100);
	std::vector<std::string> pElements = {"Dummy one", "Dummy two"};
	int pSelected = 0;

	MenuOption pOpt;
	pOpt.on_change = songChange;
	auto aPlaylist = Menu(&pElements, &pSelected, pOpt);

	ScreenInteractive screen = ScreenInteractive::Fullscreen();

	auto renderer = Renderer([&](){
			Element info = hbox({
					hbox({
							hbox({
									aImage,
									separator() | color(Color::White)
									}) | center,
							vbox({
									aInfo
									}) | center,

							}) | flex | borderStyled(ROUNDED, Color::White),
					separator() | color(Color::Orange3),
					vbox({
							aPlaylist->Render()
							}),
					filler()
					});

			auto body = vbox({
					hbox({
							filler(), text("Yoki Music Player") | bold, filler()
							}), separator() | color(Color::Orange3),
					info, separator() | color(Color::Orange3)
					}) | borderStyled(ROUNDED, Color::Orange3);

			return body;
	});

	//Render(screen, body);
	screen.Loop(renderer);
	// getchar();
	// while(1){
	// 	//Render(screen, body);
	// 	//screen.Print();
	// 	// just loop
	// }
	return 0;
}

