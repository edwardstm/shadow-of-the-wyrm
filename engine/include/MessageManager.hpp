#pragma once
#include <map>
#include "IMessageManager.hpp"

class MessageManager : public IMessageManager
{
	public:
    void clear_if_necessary() override;
    bool send(const MessageSpacing ms, const bool halt_afterwards = false, const bool reset_afterwards = false) override;
    bool send_and_halt() override;

    void alert(const std::string& message) override;
    void alert_text(const std::string& message) override;

    bool add_new_message(const std::string& message, const Colour colour = Colour::COLOUR_WHITE, const MessageImportance& importance = MessageImportance::MessageImportance_Normal) override;
    bool add_new_confirmation_message(const std::string& message, const Colour colour = Colour::COLOUR_WHITE, const MessageImportance& importance = MessageImportance::MessageImportance_Normal) override;
    bool add_new_message_with_pause(const std::string& message, const Colour colour = Colour::COLOUR_WHITE, const MessageImportance& importance = MessageImportance::MessageImportance_Normal) override;
    std::string add_new_message_with_prompt(const std::string& message, const Colour colour = Colour::COLOUR_WHITE, const MessageImportance& importance = MessageImportance::MessageImportance_Normal) override;
		
		Messages get_unread_messages() const override;
		Messages get_unread_messages_and_mark_as_read() override;

    void set_display(DisplayPtr new_display) override;

    void set_message_buffer(const MessageBuffer& new_message_buffer) override;
    MessageBuffer get_message_buffer() const override;

  protected:
    void check_message_text_for_sound_matches(const std::string& message_text, const std::map<std::string, std::string>& regex_id_and_match) const;

  private:
    std::string get_count_indicator(const Message& m);
    
    friend class MessageManagerFactory;
    MessageManager();
    MessageManager(const MessageManager&); // Do not implement!
    bool operator=(const MessageManager&); // Do not implement!
    ~MessageManager();

		Messages read;
		Messages unread;
		DisplayPtr user_display;
		bool buffer_has_messages;
    MessageBuffer message_buffer;
};
