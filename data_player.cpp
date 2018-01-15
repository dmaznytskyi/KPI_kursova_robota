#include "data_player.h"

bool data_player::operator <(const data_player& rhs) const
{
		if( score.length() > rhs.score.length() ) {
			return true;
		}
		else if( score.length() == rhs.score.length() )
		{
			if ( score.compare(rhs.score) > 0 )
			return true;
		}

		return false;
}
