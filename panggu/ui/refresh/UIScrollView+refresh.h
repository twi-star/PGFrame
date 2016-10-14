//
//  UIScrollView+refresh.h
//  PGFrame
//
//  Created by ouyanghua on 16/10/13.
//  Copyright © 2016年 pangu. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "PGBaseRefreshView.h"
#import "PGBaseMoreView.h"

@protocol PGRefreshDelegate <NSObject>

@required
//- (BOOL)isLoadingData:(UIScrollView *)scrollView;
- (void)willStartRefresh:(UIScrollView *)scrollView;
- (void)willStartLoadMore:(UIScrollView *)scrollView;

@optional


@end

#pragma mark -
@interface UIScrollView (refresh)<PGRefreshViewDelegate, PGMoreViewDelegate>

@property(nonatomic, weak)id<PGRefreshDelegate> refreshDelegate;

@property(nonatomic, strong)PGBaseRefreshView *refreshView;
@property(nonatomic, assign)BOOL bPullDownEnable;//是否能下拉刷新
@property(nonatomic, assign)BOOL bLoading;//是否正在加载数据

@property(nonatomic, strong)PGBaseMoreView *moreView;
@property(nonatomic, assign)BOOL bLoadMoreEnable;//是否能加载更多
@property(nonatomic, assign)BOOL bLoadMoring;//是否正在加载更多
@property(nonatomic, assign)BOOL bNeedLoadMoreData;//是否需要加载更多

@property(nonatomic, assign)NSInteger nNumOfPage;//每次加载的数量
@property(nonatomic, assign)NSInteger nPageIndex;//当前的页数
@property(nonatomic, assign)NSInteger nTotal;//总记录条数

- (void)startRefresh;
- (void)endRefreshing;
- (void)endLoadMoring;

#pragma mark -
- (void)pgScrollViewDidScroll;

- (void)pgScrollViewDidEndDragging;

#pragma mark -
- (void)reRefreshData;

@end
