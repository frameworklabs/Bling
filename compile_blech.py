Import("env")

env.Execute("pushd ${PROJECT_DIR}/lib/blech_src; make; popd")
