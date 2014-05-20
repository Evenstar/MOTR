rand('state',0)
nn = nnsetup([4356 100 10]);
tf_train_x=tf_train_x(1:2000,:);
tf_train_y=double(tf_train_y(1:2000,:));
opts.numepochs =  20;   %  Number of full sweeps through data
opts.batchsize = 100;  %  Take a mean gradient step over this many samples
[nn, L] = nntrain(nn, tf_train_x, tf_train_y, opts);
%%
[er, bad] = nntest(nn, tf_train_x, tf_train_y);

%assert(er < 0.08, 'Too big error');