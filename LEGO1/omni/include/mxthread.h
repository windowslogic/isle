#ifndef MXTHREAD_H
#define MXTHREAD_H

#include "compat.h"
#include "mxsemaphore.h"
#include "mxtypes.h"

class MxCore;

// VTABLE: LEGO1 0x100dc860
// VTABLE: BETA10 0x101c23e8
// SIZE 0x1c
class MxThread {
public:
	// Note: Comes before virtual destructor
	virtual MxResult Run();

	MxResult Start(MxS32 p_stackSize, MxS32 p_flag);

	void Terminate();
	void Sleep(MxS32 p_milliseconds);

	void ResumeThread();
	void SuspendThread();
	BOOL TerminateThread(MxU32 p_exitCode);
	MxS32 GetThreadPriority(MxU16& p_priority);
	BOOL SetThreadPriority(MxU16 p_priority);

	MxBool IsRunning() { return m_running; }

	// SYNTHETIC: LEGO1 0x100bf580
	// SYNTHETIC: BETA10 0x10147880
	// MxThread::`scalar deleting destructor'

protected:
	MxThread();

public:
	virtual ~MxThread();

private:
	static unsigned ThreadProc(void* p_thread);

	MxULong m_hThread;       // 0x04
	MxU32 m_threadId;        // 0x08
	MxBool m_running;        // 0x0c
	MxSemaphore m_semaphore; // 0x10

protected:
	MxCore* m_target; // 0x18
};

#endif // MXTHREAD_H
