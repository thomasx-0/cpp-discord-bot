#include <dpp/dpp.h>
#include <fstream>
#include <string>

std::string get_bot_token() {
    std::ifstream env_file("../.env");
    std::string line;
    while (std::getline(env_file, line)) {
        if (line.find("BOT_TOKEN=") == 0) {
            return line.substr(10);
        }
    }
    throw std::runtime_error("BOT_TOKEN not found in .env file");
}

const std::string BOT_TOKEN = get_bot_token();

int main() {
    dpp::cluster bot(BOT_TOKEN);

    bot.on_log(dpp::utility::cout_logger());

    bot.on_slashcommand([](const dpp::slashcommand_t& event) {
        if (event.command.get_command_name() == "ping") {
            event.reply("Pong!");
        }
    });

    bot.on_ready([&bot](const dpp::ready_t& event) {
        static bool commands_registered = false;
        if (!commands_registered) {
            commands_registered = true;
            bot.global_command_create(dpp::slashcommand("ping", "Ping pong!", bot.me.id));
        }
    });
    bot.start(dpp::st_wait);
}

// TO RUN: cd build && cmake .. && cd .. && cmake --build build/ -j4 && cd build && ./discord-bot