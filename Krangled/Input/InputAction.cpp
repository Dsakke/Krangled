#include "InputAction.h"
#include "..\ICommand.h"


KREN::InputAction::InputAction(std::unique_ptr<ICommand>&& pCommand, KeyCode keyCode)
	: m_pCommand{std::move(pCommand)}
	, m_KeyCode{ keyCode }
{
}

KREN::ICommand& KREN::InputAction::GetCommand() const
{
	return *m_pCommand;
}

void KREN::InputAction::SetCommand(std::unique_ptr<ICommand>&& pCommand)
{
	m_pCommand = std::move(pCommand);
}

KREN::KeyCode KREN::InputAction::GetKeyCode() const
{
	return m_KeyCode;
}

void KREN::InputAction::SetKeyCode(KeyCode keyCode)
{
	m_KeyCode = keyCode;
}

void KREN::InputAction::Execute()
{
	m_pCommand->Execute();
}