#include "mxsoundpresenter.h"

#include "decomp.h"
#include "mxmisc.h"
#include "mxsoundmanager.h"

DECOMP_SIZE_ASSERT(MxSoundPresenter, 0x54)

// FUNCTION: LEGO1 0x100b1a50
void MxSoundPresenter::Destroy(MxBool p_fromDestructor)
{
	if (MSoundManager()) {
		MSoundManager()->UnregisterPresenter(*this);
	}

	ENTER(m_criticalSection);
	MxMediaPresenter::Init();
	m_criticalSection.Leave();

	if (!p_fromDestructor) {
		MxMediaPresenter::Destroy(FALSE);
	}
}

// FUNCTION: LEGO1 0x100b1aa0
MxResult MxSoundPresenter::AddToManager()
{
	MxResult ret = FAILURE;

	if (MSoundManager()) {
		ret = SUCCESS;
		MSoundManager()->RegisterPresenter(*this);
	}

	return ret;
}
