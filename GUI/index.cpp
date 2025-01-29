#include <gtkmm.h>

int main(int argc, char *argv[])
{
    auto app = Gtk::Application::create(argc, argv, "org.gtkmm.example");

    Gtk::Window window;
    window.set_default_size(400, 200);

    Gtk::Button button("Click Me");
    button.signal_clicked().connect([]
                                    { std::cout << "Button clicked!" << std::endl; });

    window.add(button);
    button.show();

    return app->run(window);
}
