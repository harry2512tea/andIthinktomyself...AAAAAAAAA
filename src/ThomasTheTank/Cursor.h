

namespace ThomasTheTank
{
	enum CursorLockMode
	{
		None,
		Locked,
		Confined
	};


	struct Cursor
	{
		static CursorLockMode lockState;
		static bool visible;
	};
}