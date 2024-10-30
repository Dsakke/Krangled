#include "MoveCommand.h"
#include <Transform.h>

MoveCommand::MoveCommand(std::weak_ptr<KREN::Transform> pTransform)
	: m_pTransform{ pTransform }
{
}

void MoveCommand::Execute()
{
	std::shared_ptr<KREN::Transform> pTrans = m_pTransform.lock();
	pTrans->SetPosition(pTrans->GetPosition() + KRM::FVector3{ 1,0,0 });
}
