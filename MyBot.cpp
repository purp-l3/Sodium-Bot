#include <dpp/dpp.h>
#include <dpp/cluster.h>
#include <dpp/commandhandler.h>
#include "../../sodiumSentence/WordManager.h"
#include "../../sodiumSentence/SodiumSentence.h"

/* Be sure to place your token in the line below.
 * Follow steps here to get a token:
 * https://dpp.dev/creating-a-bot-application.html
 * When you invite the bot, be sure to invite it with the
 * scopes 'bot' and 'applications.commands', e.g.
 * https://discord.com/oauth2/authorize?client_id=940762342495518720&scope=bot+applications.commands&permissions=139586816064
 */
const std::string    BOT_TOKEN = "notApplicable";

std::vector< std::vector<std::string> > words = WordManager::loadWords("words.dat");
std::vector< std::string > formats = WordManager::loadFormats("sentenceFormats.dat");



int main()
{


    /* Create bot cluster */
    dpp::cluster bot(BOT_TOKEN);

    /* Output simple log messages to stdout */
    bot.on_log(dpp::utility::cout_logger());

    /* Handle slash command */
    bot.on_slashcommand([](const dpp::slashcommand_t& event) {
        if (event.command.get_command_name() == "ping") {
            event.reply("Pong!");
        }
        else if (event.command.get_command_name() == "saysomething") {
            std::string Pnoun = event.command.usr.format_username();
            SodiumSentence currSentence(formats, words, Pnoun);
            std::cout << Pnoun << " called the command - ";
            currSentence.print();
            event.reply(currSentence.getSentence());
        }
        });

    /* Register slash command here in on_ready */
    bot.on_ready([&bot](const dpp::ready_t& event) {
        SodiumSentence::init();

        /* Wrap command registration in run_once to make sure it doesnt run on every full reconnection */
        if (dpp::run_once<struct register_bot_commands>()) {
            bot.global_command_create(dpp::slashcommand("ping", "Ping pong!", bot.me.id));
            bot.global_command_create(dpp::slashcommand("SaySomething", "Make a funny random sodium sentence", bot.me.id));
        }
    });

    /* Start the bot */
    bot.start(false);

    return 0;
}
