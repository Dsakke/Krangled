#pragma once
#include "ICommand.h"
#include "Transform.h"
#include <memory>

class MoveCommand final : public KREN::ICommand
{
public:
	MoveCommand(std::weak_ptr<KREN::Transform> pTransform);
	void Execute() override;

private:
	std::weak_ptr<KREN::Transform> m_pTransform;
};

