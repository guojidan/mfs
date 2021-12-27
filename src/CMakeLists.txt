set(chunkserver_src
    chunkserver.cc
    common/mfs_argparse.cc
)

add_executable(ChunkServer ${chunkserver_src})

# target_link_libraries(ChunkServer ArgParse)