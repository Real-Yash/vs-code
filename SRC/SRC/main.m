clc;
close all;
clear all;

% To read images from file..
[filename, pathname] = uigetfile('*.*','Load Image 1 ');cd(pathname);
im1=imread([pathname,filename]);
[filename, pathname] = uigetfile('*.*','Load Image 2 ');cd(pathname);
im2=imread([pathname,filename]);

figure(1);
subplot(121);imshow(im1,[]);
subplot(122);imshow(im2,[]);

% image decomposition using discrete stationary wavelet transform
[A1L1,H1L1,V1L1,D1L1] = swt2(im1,1,'sym2');
[A2L1,H2L1,V2L1,D2L1] = swt2(im2,1,'sym2');
% fusion start
AfL1 = 0.5*(A1L1+A2L1);
D = (abs(H1L1)-abs(H2L1))>=0;
HfL1 = D.*H1L1 + (~D).*H2L1;
D = (abs(V1L1)-abs(V2L1))>=0;
VfL1 = D.*V1L1 + (~D).*V2L1;
D = (abs(D1L1)-abs(D2L1))>=0;
DfL1 = D.*D1L1 + (~D).*D2L1;
% Fused Image
imf = iswt2(AfL1,HfL1,VfL1,DfL1,'sym2');
figure(2); imshow(imf,[]);




% compute PCA 
im1 = double(im1);
im2 = double(im2);
C = cov([im1(:) im2(:)]);
[V, D] = eig(C);
if D(1,1) >= D(2,2)
  pca = V(:,1)./sum(V(:,1));
else  
  pca = V(:,2)./sum(V(:,2));
end
% Fused Image
imf = pca(1)*im1 + pca(2)*im2;
figure(3); imshow(uint8(imf),[]);

%% Otsu segmentation..
imf = uint8(imf);
level = graythresh(imf);
seg=im2bw(imf,0.7);
figure(4),imshow(double(seg),[]);

%performance analysis for fused image
std_dev=std2(imf);
disp('standard deviation of fused image=');
disp(std_dev)



%performance analysis for seg image
std_dev1=std2(seg); 
disp('standard deviation of segmented image=');
disp(std_dev1)

% [Gmag, Gdir] = imgradient(seg,'prewitt');

%%gradient of fused image
g=imgradient(imf);
g=g(1,:);
grad=mean(g);
disp(' gradient of fused image=');
disp(grad)

%%gradient of segmented image
g1=imgradient(seg);
g1=g1(1,:);
grad1=mean(g1);
disp(' gradient of segmented image=');
disp(grad1)

%%spectral discrepancy of fused image
sd=fft(imf);
sd=sd(1,:);
sd=mean(sd);
sd=real(sd);
disp('spectral discrepancy of fused image=')
disp(sd)

%%spectral discrepancy of segmented image
sd=fft(seg);
sd=sd(1,:);
sd=mean(sd);
sd=real(sd);
disp('spectral discrepancy of segmented  image=')
disp(sd)


%% feature extraction
% level = graythresh(c)
% seg=im2bw(c,level)
% figure(4),imshow(seg);


x = double(seg);
m = size(seg,1);
n = size(seg,2);

signal1 = seg(:,:);


%% Haar Feature Extraction..
[cA,cH,cV,cD] = dwt2(seg,'haar');
cA = mean2(cA);
cH = mean2(cH);
cV = mean2(cV);
cD = mean2(cD);

Mean = mean2(seg);
Standard_Deviation = std2(seg);
Entropy = entropy(seg);
Variance = mean2(var(double(seg)));
a = sum(double(seg(:)));
Smoothness = 1-(1/(1+a));
Kurtosis = kurtosis(double(seg(:)));
Skewness = skewness(double(seg(:)));
% Inverse Difference Movement
m = size(seg,1);
n = size(seg,2);
in_diff = 0;
for i = 1:m
    for j = 1:n
        temp = seg(i,j)./(1+(i-j).^2);
        in_diff = in_diff+temp;
    end
end
IDM = double(in_diff);
    
featext_fcm = [Mean, Standard_Deviation, Entropy,Variance, Smoothness, Kurtosis, Skewness, IDM, cA, cH,cV,cD];

%% Classifier..
load Trainfeat_fcm.mat
load label.mat

xdata = Trainfeat_fcm;
group = label;

% svmstruct = svmtrain(xdata,group);
% Result =  svmclassify(svmstruct, featext_fcm);
% xdata = Trainfeat;
% group = label;
svmstruct = fitcsvm(xdata,group,'KernelFunction', 'linear');
[Result,s] = predict(svmstruct, featext_fcm );
if Result == 1
    msgbox('BENGIN');
else
    msgbox('MALIGANT');
end
%% Performance Analysis..
% load Result_fcm.mat
% cp = classperf(label,Result_fcm);
% accuracy = cp.CorrectRate
% sensitivity = cp.Sensitivity
% specificity = cp.Specificity
% confusionmat = confusionmat(label,Result_fcm);
% 
% 
% 
% 



