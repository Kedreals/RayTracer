v = ARGV[0]
if v == nil
  puts "ruby build.rb [all/exe/doc] [optional: -open_doc [browser = firefox]]"
end
if v == "doc" || v == "all"
  system('doxygen ../Doxyfile')
end
if ARGV[1] != nil
  if ARGV[2] == nil
    system('firefox Documentation/html/index.html')
  else
    system(ARGV[2] + ' Documentation/html/index.html')
  end
end
if v == "exe" || v == "all"
  if !system('cmake ../')
    return
  end
  if !system('make')
    return
  end
  if !system('./ray_tracer')
    return
  end
  system('xdg-open test.ppm')
end
