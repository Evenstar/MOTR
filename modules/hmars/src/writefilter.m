fid=fopen('filter.txt','w');
fprintf(fid,'%d %d \n',r*r,r*r);
dict=sortdict(dict);
for i=1:r*r
    for j=1:r*r
        fprintf(fid,'%8.4f ',dict(i,j));
    end
            fprintf(fid,'\n');
end
fclose(fid)