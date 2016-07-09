require('areas')

local nether_shrine = Area:new(97, 2)
nether_shrine:set_extra_description_sid("TILE_EXTRA_DESCRIPTION_NETHER_SHRINE")
nether_shrine:set_tile_subtype(13) -- always on a marsh
nether_shrine:set_additional_properties({["MAP_PROPERTIES_RELIC_ID"] = "heart_world_beyond",["MAP_PROPERTIES_CREATURE_IDS"] = "spectral_lord,spectral_emperor,hellhound,pit_fiend,abyssal_beast,astral_horror"})

nether_shrine:insert()

